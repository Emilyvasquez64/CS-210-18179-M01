# CS-210-18179-M01
Summarize the project and what problem it was solving.
This project was a grocery tracker that reads a file full of grocery items and keeps track of how many times each item shows up. It helps solve the problem of figuring out which items were bought the most or the least, kind of like making a report from a shopping list. The program also lets the user type in an item to check how often it was bought, print out all the items with their counts, or see a histogram made of stars to visualize how popular each item was. It even creates a backup file of the data automatically.

What did you do particularly well?
I think I did a good job organizing the code and making the program user-friendly. The menu is clear, and the outputs are easy to read. I also made sure the program checks if the file exists and handles errors in case the user types something wrong. One part I liked was how I made the histogram line up nicely by figuring out the longest product name and using spaces. That made everything look neat.

Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I could improve the code by not using a raw pointer when creating the GroceryBookKeeper object. Instead, I could use a smart pointer like unique_ptr so I don’t have to worry about deleting it later, which is safer. I could also add more checks for the input, like making sure the user doesn't type random stuff that crashes the program. Maybe even let the user choose where the backup file gets saved, instead of always using the /tmp/ folder.

Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The hardest part for me was the histogram. At first, the stars didn’t line up properly, and it looked messy. I fixed it by figuring out how many spaces each product needed to match the longest word, so the stars would start at the same spot. I used Google and C++ forums to learn how to use map, getline, and formatting tools. I also practiced a lot by testing the program with fake grocery lists to make sure it worked right.

What skills from this project will be particularly transferable to other projects or course work?
I learned how to use file reading and writing in C++, which is super useful for other classes or projects. Using a map to count things is something I’ll definitely use again. I also got better at debugging and thinking about all the little things that could go wrong, like bad input or empty files. Plus, I practiced organizing code using classes and functions, which makes programs way easier to understand.

How did you make this program maintainable, readable, and adaptable?
I kept my code clean by splitting it into small functions and using a class to group all the grocery tracking stuff. I named my variables in a way that makes sense, like productTofrequency for the map. I also added comments throughout the code to explain what each part does, so it would be easy to come back to later or for someone else to read. If I wanted to add more features, like sorting or saving files somewhere else, it wouldn’t be that hard because everything is organized.
