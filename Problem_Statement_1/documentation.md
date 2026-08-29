
 LEVEL 1


ProblemUnderstanding
What the problem is asking: so it is basically asking us to simulate G generation of some process(which give us 3,4 conditions) and output the final generation with initial,final and peak population along the process

Key concepts involved: main algorithm are just the if else conditions to update the generation and save it into another vector

My approach: i just followed that saved intial generation in a vector and after following the rules 1 time i save it in copyvector and after the loop i save copyvector into the original vector running the loop many times.to find peak population i saved all the population along lopp in a peak vector.at the end i sorted that vector and printed the peak population

Conceptual Learning
New Concepts I Discovered
[Concept Name]: using of 2D vector to my benifit
[Another Concept]: boundary condition for a matrix 
How I Applied These Concepts
u used 2d vector to save the current generation and use if condition to signify the boundary conditions

Real-World Connections:
this is the most basic program or simulation  we can build using a condition as it has only 2 states and 3 conditions.we can build onto it from here upping the states and conditons

LEVEL 2

Problem Understanding
What the problem is asking: so the question is asking to basically connect all the four sides like a toroid and also asking us to classify all pattern into 4 states according to their condition in the next 10 terms.3rd feature is just basic asking us to find com of the live cells and boundness

Key concepts involved: for the feature 1 the main thing is how to tackle the outside the boundary connecting for that we use mod as it direct modifes the outside boundary to connect it to the other side.
for the classifcation,main thing used is 3D vector basically saving each generation in 2D vector and then combining a 3d vector.for checking extinct ,we count the population in each generation and save it into a peak vector .then if we find 0 in peak vector we can classify it into extinct .for the oscillation part we just map each generation with all the previous generation and when we find a match we stop the process. still life is just a oscillator with period 1.
for the feature 3,we have to initiral only so we just save all the x and y coords in a different and vector and later used it to find com and boundness

My approach: i explained all my approach above

Conceptual Learning
New Concepts I Discovered
[Concept Name]: 3D vector allocation and use of set precision
[Another Concept]: toroidal coordination basically use of the modulus to help connect spaces
How I Applied These Concepts
i just used 3d vector to save all the generation so i can acess them later and used modulus to connect all boundaries

Real-World Connections
we can use the feature 1 in real life games to connect the whole space without limiting the game much

 LEVEL 3

 Problem Understanding
What the problem is asking: the problem is asking to generate regularly updating generation as the loop runs

Key concepts involved: main idea used is the chrolo and thread library concept

My approach: although chrolo and thread is superior concept but it is not working for my compiler so i have used the windows.h and used the system"cis" to remove the already printed generation and flush and sleep 

Conceptual Learning
New Concepts I Discovered
[Concept Name]: sleep and flush function
[Another Concept]: system{cis} to clear the entire 
How I Applied These Concepts
i just used basic use of sleep flush and system (cis)

Real-World Connections
most real world websites are self updating so this is good way to learn recurring animation etc
