# NumbersRecognitionApp
NRA is an app made of my three programs that can recognize hand written digits. 
The library I used to create neural network, test and run it was made by friend of mine, 
I'm obligated to share his GitHub account: http://github.com/DrwalinPCF

Libraries Used:

NeuralNetwork - Library made by Marek Zalewski aka Drwalin aka DrwalinPCF
https://github.com/DrwalinPCF/NeuralNetwork
SFML - Simple and Fast Multimedia Library
https://www.sfml-dev.org
Rest of libraries, are just standard libraries, like iostream, or fstream.

NRA consist of 3 programs:

NNN - Numbers Neural Network
This program learns how to recognize hand written digits, from MNIST data set.

dataPrep - Data Preparation
This program takes pictures of many digits from MNIST, and then using SFML changes them to array of 0's or 1's according to luminiscence of each pixel.

PA - PaintApp
Program which allows you to draw, and save images you drew. Not only it saves what u drew but it scales it to 28x28 image like the data from MNIST is saved, so the dataPrep app can prepare inputs and pass it to NNN to finally get predicted number.

