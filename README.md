# Poem Box
This project was created for the Poetry Club at Stevens Institute of Technology.

![Image of the box printing a poem](https://static.wixstatic.com/media/b6c492_9d53dd95609a43a881cc3efa2e89b5b6~mv2_d_2048_1365_s_2.jpg/v1/fill/w_538,h_356,al_c,q_80,usm_0.66_1.00_0.01/better%202.webp)

## Introduction
By pressing the glowing button at the top, the box randomly selects one of the stored poems and prints it onto thermal paper. This project was created using an Arduino Pro Trinket, a thermal printer, and an LED pushbutton.  Using the Arduino IDE, nineteen poems were stored in flash onto the microcontroller. When the button at the top of the box is pressed, the Arduino turns off the LED in the button and randomly selects one of the poems. The poem is sent to the thermal printer, which then prints it out at the front of the box. When the thermal printer has finished printing, the Arduino turns on the LED again, indicating that it's ready to print again.

poem.ino was the code that was used for this project. parm.ino was based on this code and was created for a gift. Instead of poems, it prints a pauris from the Japji Sahib.

## BOM:
* Arduino Pro Trinket
* LED pushbutton
* Thermal printer guts
* Female barrel jack
* Michael's wooden box
