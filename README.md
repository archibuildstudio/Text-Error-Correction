# Text-Error-Correction
Sentence Cleaner and Analyzer in C++
📌 Description
This C++ program helps process and analyze a raw paragraph or sentence. It takes a possibly messy input (with special characters or random capitalization), cleans it up, and gives you useful information like:

- Corrected and cleaned sentence (special characters removed, proper casing)
- Total word count
- Word frequency analysis
- Word replacement feature (you can replace any word in the sentence)
🚀 How It Works
Step-by-Step:
1. The program asks you to enter a sentence or paragraph.
2. It cleans the text by:
   - Removing special characters (like @#$%&*), keeping only letters, numbers, commas, periods, and spaces.
   - Capitalizing the first letter.
   - Making the rest lowercase.
3. It prints the corrected sentence.
4. It counts how many words there are.
5. It analyzes the frequency of each word.
6. Finally, it asks you to replace a word with a new one and shows the updated text (highlighted using < >).
📥 Input Example
I l@ov!e @#you witho%ut a si*ng&le hesit%$ation.
📤 Output Example
Corrected Sentence:
I love you without a single hesitation.

Word count: 7

Word frequencies:
i: 1
love: 1
you: 1
without: 1
a: 1
single: 1
hesitation: 1

Enter a word to replace: love
Enter the new word: adore

Updated Paragraph:
I <adore> you without a single hesitation.

🛠️ How to Run
Requirements:
- A C++ compiler (like g++)
- A terminal or IDE like Code::Blocks, VS Code, or Dev-C++

Compile the code:
g++ -o text_analyzer main.cpp

Run the program:
./text_analyzer

📂 File Structure
text_analyzer/
├── main.cpp       ← Source code
└── README.docx    ← You're reading it!
👨‍💻 Author
Made with ❤️ to help beginners understand how to clean and process text in C++.
