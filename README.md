# Getting Started with ESP-IDF

## Project Configuration

Based on ["ESP32 - Getting Started with ESP-IDF using Visual Studio Code [Easiest Method]"](https://www.youtube.com/watch?v=5IuZ-E8Tmhg) and ["ESP32 - How to create your First ESP IDF project (From Scratch)"](https://www.youtube.com/watch?v=oHHOCdmLiII).

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
		"terminal.integrated.tabs.title": "ESP-IDF Terminal",
		"terminal.integrated.env.windows": {
			"IDF_TOOLS_PATH": "C:\\Espressif",
			"PATH": "C:\\Espressif\\python_env\\idf4.4_py3.8_env\\Scripts;${env:PATH}"
		},
		"terminal.integrated.shell.windows": "cmd.exe",
		"terminal.integrated.shellArgs.windows": [
			"/k",
			"C:\\Espressif\\frameworks\\esp-idf-v4.4\\export.bat"
		],
	}
}
```

["QUICK FIX for IDF Terminal inside VS CODE"](https://www.youtube.com/watch?v=N93RvZz6dEc)

### Step 4: Create a Blank Project Using `idf.py`

```bash
idf.py create-project blank_poject
```

### Step 5: Configure the Project using `menuconfig`

It is important to add `start` keyword before `idf.py menuconfig` to open it in a new window. Otherwise, it will open in the VSCode terminal and up/down arrow keys will not work.

```bash
start idf.py menuconfig
```

#### Set Clock Speed

`Component Config > ESP32-specific > CPU frequency > 240MHz`

#### Set Flash Memory Size

According to LOLIN32 board, the flash size is 4MBytes.

`Serial flasher config > Flash size > 4MB`

#### Save Setting

After saving the `menuconfig` settings, two files will be created: `sdkconfig` and `sdkconfig.old`.
Also a `build` folder will be created for project build outputs. Put the `build` folder in the `.gitignore` file.

### Step 6: Build the Project

Note: According to the contents of `$ENV{IDF_PATH}/tools/cmake/project.cmake` the name of the directory containing source files
should be `main`.

```bash
idf.py build
```

### Step 7: Flash

idf.py flash -p COM1

### Step 8: Monitor

```bash
idf.py monitor -p COM1
```

### Step 9: Clean the Build Directory

```bash
idf.py fullclean
```

### Step 10: Run (Build, Flash, and Monitor)

```bash
idf.py flash -p COM1 -b 921600 monitor
```

### Step 11: Debug

Based on ["ESP32 - DEBUGGING your ESP-IDF code using JTAG [VS CODE]"](https://www.youtube.com/watch?v=uq93H7T7cOQ)

#### OpenOCD

Start OpenOCD GDB server on port 3333.

```bash
openocd -f interface/jlink.cfg -f board/esp-wroom-32.cfg -c "set ESP32_FLASH_VOLTAGE 3.3"  -c "set ESP_RTOS none" -c "adapter speed 1000"
```

## Board Pinout

WeMos LOLIN32 V1.0

![](assets/esp32-lolin32.png)

## References

- [Standard Setup of Toolchain for Windows](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/windows-setup.html)
- [Set global $PATH environment variable in VS Code](https://stackoverflow.com/questions/43983718/set-global-path-environment-variable-in-vs-code)