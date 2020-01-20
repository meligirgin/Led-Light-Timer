# Led-Light-Timer

Device: STM32F407G
Software Apps: Keil uVision5

STORY

When the user presses a button on the circuit for a short time, an LED in the same circuit will be taken into the "short press mode" cycle and when it is pressed for a long time, it will be taken into the "long press mode" cycle. Mentioned modes;Short press mode: Twice 1 second blink cycle, Twice 2 second blink cycle(On1sn-off1sn-on1sn-off1sn-on2sn-off2sn-on2sn-off2sn-on1sn-off1sn...)Long press mode: four times 1 second flash, four times 2 second flash cycle(On1sn-off1sn-on1sn-off1sn-on1sn-off1sn-on1sn-off1sn-on2sn-off2sn-on2sn-off2sn-on2sn-off2sn-on2sn-off2sn-on1sn-off1sn...)Rules:- 100ms debounce time will be used when the button is detected. Long press time is 3 seconds.- The application starts in short press mode.- Pressing the button will not affect the flashing cycle of the LED. As long as the button is held down, the LED will continue in the cycle of the mode it is in. If the mode change is required when the button is released, the cycle restarts in accordance with the new mode (eg short press in long press mode). If the mode change is not required (eg long press the button again in long press mode), the LED cycle will continue as if the button was never pressed.
