# Getting Started with ESP-IDF

## Project Configuration

Based on ["ESP32 - Getting Started with ESP-IDF using Visual Studio Code [Easiest Method"]](https://www.youtube.com/watch?v=5IuZ-E8Tmhg) and ["ESP32 - How to create your First ESP IDF project (From Scratch)"](https://www.youtube.com/watch?v=oHHOCdmLiII).

### Step 1: Download and Install VSCode

https://code.visualstudio.com/


### Step 2: Download and Install ESP-IDF

https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/index.html

### Step 3: Create a Workspace for ESP-IDF in VSCode

`File > Save Workspace As... > start-esp-idf.code-workspace`

Add ESP-IDF Terminal parameters for Windows:

```json
{
	"folders": [
		{
			"path": "."
		}
	],
	"settings": {
		"terminal.integrated.shell.windows": "cmd.exe",
		"terminal.integrated.shellArgs.windows": [
			"/k",
			"C:/Espressif/frameworks/esp-idf-v4.4/export.bat"
		],
	}
}
```


## Board Pinout

WeMos LOLIN32 V1.0

![](assets/esp32-lolin32.png)