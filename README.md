# PM2.5 Sensor(HM3301)  [![Build Status](https://travis-ci.com/Seeed-Studio/Seeed_PM2_5_sensor_HM3301.svg?branch=master)](https://travis-ci.com/Seeed-Studio/Seeed_PM2_5_sensor_HM3301)

HM-3301 is a new generation of dust detection sensor based on laser theory introduced by our company, which is used for continuous and real-time detection of dust in the air.  

![HM3301](https://user-images.githubusercontent.com/41441945/44911054-11abd000-ad58-11e8-9b38-d2d504a86411.jpg)  




##  Introduction:  
The HM-3301 is applicable to products and application fields such as dust detectors, intelligent air purifiers, intelligent air conditioners, intelligent ventilation fans, air quality detection, haze table, environment monitoring, etc.



## Usage:  
- Download all the source files and open one of examples, compile, upload, and run. Open the Serial Port and set the baud rate to **115200** to watch the result.
-  Example: open the file examples/basic_demo/basic_demo.ino. This is the three-way test, which can measure the concentration content of three levels :PM1.0,PM2.5,PM10.

## Notice:

- The sensor metal housing should not be short-circuited with other external panel circuits or product housing because the sensor housing is conducting the internal power source.
- When applying with purifier or fixed detection equipment, the position of the sensor should be higher than 20cm above the ground. Otherwise, it is likely to be polluted by large dust particles or even floccules near the ground, resulting in the winding resistance of the fan. Refer to doc/HM-3300&3600datasheet.doc for more details.



### reference:

Datasheet:refer to **HM-3300&3600datasheet.doc**  


***
This software is written by downey  for seeed studio<br>
Email:dao.huang@seeed.cc
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>

