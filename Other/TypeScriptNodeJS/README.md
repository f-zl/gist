# TypeScript with NodeJS

Minimal TypeScript with NodeJS projects that can build and run

ESM
- package.json:
	```
	"type": "module",
	"devDependencies": {
		"@types/node": "^26.5.0",
		"typescript": "^7.0.2"
	}
	```
- tsconfig.json:
	```
	"module": "nodenext",
	"moduleResolution": "nodenext",
	"types": [ "node" ],
	```
- main.ts: `import { f } from "./a.js";`

CJS
- package.json: omit `"type"` or use `"type": "commonjs"`
	```
	"devDependencies": {
		"@types/node": "^26.5.0",
		"typescript": "^7.0.2"
	}
	```
- tsconfig.json: same as in ESM\
	tsc will use `"type"` in package.json or script file extension to output ESM/CJS code\
	Note TypeScript 7 doesn't allow `"module": "node"`
- main.ts: `import { f } from "./a";`\
	`const a = require("./a")` compiles but tsc can't infer types
