# STM32F401RE
Apps and Drivers for STM32F401RE microcontroller. This was made for educational purposes. Reporting any test results, comments, or bugs will be appreciated.

This Repo consists of four main folder types:
  1. LIB: Folder that contains the vertical layer's files (standard libraries), There is only one "LIB" folder.
  2. MCAL: Folder that contains the micro controler abstraction layer drivers, and there is only one MCAL folder that stores the latest versions
		of the MCAL drivers.
  3. HAL: Folder that contains the hardware abstraction layer drivers, and there is only one HAL folder that stores the latest versions of the
		HAL drivers
  4. APP_x_app-name: App folder that contains the main app and its generated files from the build process, and there is a folder for each project.
  5. APP_x_app-name_SIM: Simulation folder contains simulation files created with proteus simulation.
Note: All projects was created and developed on STM32CubeIDE.

At last, there is a file called Template_prog containing template main and template make file for manual use (without SDK).