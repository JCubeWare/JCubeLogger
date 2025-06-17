![JCubeLogger_Logo](https://jcubeware.com/Public/Images/JCubeLogger.png)

## ⚠️  Notice  ⚠️

**This project is heavily in development. 
The reason for the early upload is to display our coding convention in action.**

### 🗒️ TODO

#### Customization
- [ ] Broader filestream support.  
- [ ] Log levels.
- [ ] Logging format.
- [ ] Logger Rules (f.e. skip certain words)

#### Functionality
- [ ] Max line length.
- [ ] Buffer mode (Log is first put into a buffer, then printed)

## 📚  About  📚

JCubeLogger is a C/C++ library designed to heavily simplify logging.
Each logger has its own instance, allowing you to have several independent
loggers each to perform accordingly.

The logging has in-built priority system, string sanitation and is easy to
set up, requiring only the StartLogger() and EndLogger() functions.

## 💼  Usage  💼

```c
#include <JCubeLogger_0.0.1/JCubeLogger.h>

JCubeLogger_t Logger;
JCubeLogger_Settings_t LoggerSettings = {
	.Filename = "test.txt",
	.ModuleName = "Test Module",
	.ShowModuleName = 1,
	.UseConsole = 1,
	.ShowFunctionName = 1,
	.MinimalLogLevel = JCubeLogger_DEBUG
};

JCubeLogger_StartLogger(&Logger, LoggerSettings);

JCubeLogger_PrintLog(&Logger, JCubeLogger_DEBUG, "Hello world!");

JCubeLogger_StopLogger(&Logger);
```

## 📦  Building  📦

To build and install the library, follow these simple steps:

_**Terminal (Command Prompt / Powershell for Windows)**_
```
git clone https://github.com/JCubeWare/JCubeLogger.git
cd JCubeLogger
make
sudo make install
```

## 🌐  License  🌐

This project is licensed under the MIT license.

[LICENSE](LICENSE)