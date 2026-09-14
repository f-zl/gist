// add prefix for global symbols to avoid conflict
reg[1:0] apbState;
localparam APB_IDLE = 2'b00;
localparam APB_SETUP = 2'b01;
localparam APB_ACCESS = 2'b10;
assign APB_PREADY = apbState == APB_ACCESS;

always @(posedge APB_PCLK) begin
	if (!APB_PRESETn) begin
		apbState <= APB_IDLE;
		OnReset();
	end else begin
		case (apbState)
		default:begin // APB_IDLE
			if (APB_PSELx)
				apbState <= APB_SETUP;
		end
		APB_SETUP:begin
			if (APB_PENABLE) begin // assume always ready in a step
				apbState <= APB_ACCESS;
				if (APB_PWRITE) begin
					OnWrite(APB_PADDR, APB_PWDATA, APB_PSTRB);
				end else begin
					APB_PRDATA <= OnRead(APB_PADDR);
				end
			end
		end
		APB_ACCESS:begin
			if (!APB_PSELx) begin
				apbState <= APB_IDLE;
			end else if (!APB_PENABLE) begin
				apbState <= APB_SETUP;
			end
		end
		endcase
	end
end
