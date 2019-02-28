# Minika_Kollision
<p>Arduino-based solution for Minika Ko fashion, tech and art show, "Kollision."<br> 
This code was deployed to LilyPad (Arduino) and Flora (Adafruit) controllers<br>
to produce lighting patterns with attached NeoPixel LED Strands (Adafruit). <br>
Within the code, I added variable controls so the program could easily be <br>
modified by the end-user.</p>

<p><strong><a href="https://www.minikako.com/kollision">Kollision website</a></strong></p>

<p>In collaboration with artist Vanessa Sun.</p>

<p><img src="https://static1.squarespace.com/static/55f89062e4b0eb0e544148bc/t/5c452eb988251ba079651ab9/1548037848144/minika-ko-kollision-2019.jpg?format=2500w">

<p><strong>Instructions for running app</strong></p>
<p>Build: Arduino 1.8.6; Arduino AVR Boards 1.6.22 (LilyPad);<br>
          AdaFruit AVR Boards 1.4.13 (Flora); AdaFruit NeoPixel 1.1.8</p>
<p>Deploy: LilyPad Arduino, Processor ATmega328P, Port Dev/ttyUSB1<br>
          AdaFruit Flora, Port Dev/ttyACM0 (AdaFruit Flora)<br>
          AdaFruit NeoPixel LED Strand</p>

<p><strong>Test output: ConvergePattern function</strong></p>

<p>This function sets and resets LED lights in two sequences -- in this case, one<br>
sequence starting from light 0 and one sequence starting from light 19 -- with <br>
the patterns converging to the midpoint of the strand. Additionally, through each<br>
successive cycle, the color output is altered to the following: red, orange, pink, <br>
magenta, and purple. The color output reverts back to red after reaching the last<br>
cycle.</p>
          
<p><em>This sequence may be used with multiple LED strands by modifying the number<br>
of LEDs on line 27.</em></p>

<p><strong>Video snippet:</strong></p>
<p><img src="https://github.com/LawrenceCastillo/Minika_Kollision/blob/master/TestOutput/TestOutput_ConvergePattern.gif">

<p><strong>Test output: RandomizePattern function</strong></p>

<p>This function randomly sets and resets LED lights two at a time: one each in the<br>
top and bottom half of the strand. The intention is to invoke a sense of neural <br>
activity and to always maintain at least one LED on each <i>side of the brain</i>, so to<br>
speak. Additionally, through each successive cycle, the color output is altered to<br> 
shades of the following: orange, yellow, and white. The color output reverts back <br>
to orange after reaching the last cycle.</p>
          
<p><em>This sequence may be used with multiple LED strands by modifying the number<br>
of LEDs on line 27.</em></p>

<p><strong>Video snippet:</strong></p>
<p><img src="https://github.com/LawrenceCastillo/Minika_Kollision/blob/master/TestOutput/TestOutput_RandomizePattern.gif">
