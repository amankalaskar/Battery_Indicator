![GitHub repo size](https://img.shields.io/github/repo-size/amankalaskar/Battery_Indicator?style=plastic)
![C/C++ CI](https://github.com/amankalaskar/Battery_Indicator/workflows/C/C++%20CI/badge.svg)
![cppcheck-action](https://github.com/amankalaskar/Battery_Indicator/workflows/cppcheck-action/badge.svg)

# Battery_Indicator

This application allows you to broadcast your battery percentage over the xampp server. In addition it also alerts you if the battery percentage is going out of bound.

*  How to make it work:
    *  Copy the following files to the "C:\xampp\htdocs".
        *  main.c
        *  show.php
    *  Run the "main.c" file using gcc compiler.
    *  A text file gets generated. 
    *  This "battery_status.exe" feeds the data like battery percentage and charging status to the "show.php" file.
    *  Turn on the xampp server using the control panel or cmd line.
    *  Open a browser(Google Chrome is preferable) and open the localhost page. Wola! 
    *  To see this status on the mobile platform, connect the mobile to the same network of your laptop and feed the ip address to the mobile browser.
