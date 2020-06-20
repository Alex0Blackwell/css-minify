#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <assert.h>

using namespace std;

/**
 * Check and return if the ./files/original.txt file is empty
 */
bool isEmpty(void) {
  ifstream file("./files/original.css");
  return (file.peek() == ifstream::traits_type::eof());
}


/**
 * sanitize input by allowing content of specified type T
 */
template <typename T>
T getInput(void) {
  T usrChoice;
  string line;
  while(getline(cin, line)) {
    stringstream ss(line);
    if(ss >> usrChoice) {
      if(ss.eof())
      break;
    }
    cout << "You must enter valid input!" << endl;
  }
  return usrChoice;
}


/**
 * asks for if the user wants their minified content
 * outputted to the terminal, or if they want it in a file.
 */
void minify(void) {
  string allText, textIn, res;

  ifstream inFile("./files/original.css");

  // write to a string called allText
  while(getline(inFile, textIn))
    allText += textIn;
  inFile.close();

  // delete comments, allow for syntax such as "margin: 0 20px"
  bool inComment = false;
  for(unsigned int i = 0; i < allText.size(); ++i) {
    if(!inComment) {
      if(allText[i] == '/' && i+1 < allText.size() && allText[i+1] == '*')
        inComment = true;
      else if(isdigit(allText[i])) {
        if(allText[i-1] == ' ' && allText[i-2] != ':')
          res += " ";
        res += allText[i];
      }
      else if(allText[i] != ' ')
        res += allText[i];
    }
    else if(allText[i] == '/' && i-1 > 0 && allText[i-1] == '*')
      inComment = false;
  }

  cout << "Do you want your text:\n1) saved to a file\n2) outputted to the terminal" << endl;
  int usrChoice;
  while(usrChoice != 1 && usrChoice != 2) {
    cout << "Enter a choice (1 or 2)" << endl;
    usrChoice = getInput<int>();
  }

  if(usrChoice == 1) {
    // save to file of selected type
    cout << "Generating minified.min.css"<< endl;
    ofstream outFile("./files/minified.min.css");
    outFile << res;
    outFile.close();
    cout << "Finished!" << endl;
  } else {
    // print to terminal
    assert(usrChoice == 2);
    cout << "\nYour minified CSS:\n\n" << res << endl;
  }

  return;
}


int main(void) {
  // remove past minified files
  remove("./files/minified.min.css");

  if(!isEmpty()) {
    // then minify
    minify();
    // delete what was in the original.txt file
    ofstream del;
    del.open("./files/original.css", ofstream::out | ofstream::trunc);
    del.close();
  } else {
    cout << "Your original.txt file is empty" << endl
    << "...so I guess we did a really good job minifying it :)" << endl
    << "Enter your program into the \"./files/original.css\" file for it to be minified!" << endl;
  }

  return 0;
}
