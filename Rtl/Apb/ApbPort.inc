input APB_PCLK,
input APB_PRESETn,
input [APB_ADDR_WIDTH-1:0] APB_PADDR,
// PPROT, PNSE are not used
input APB_PSELx,
input APB_PENABLE,
input APB_PWRITE,
input [APB_DATA_WIDTH-1:0] APB_PWDATA,
input [(APB_DATA_WIDTH/8)-1:0] APB_PSTRB,
output APB_PREADY,
output reg[APB_DATA_WIDTH-1:0] APB_PRDATA
// PSLVERR, PWAKEUP are not used
