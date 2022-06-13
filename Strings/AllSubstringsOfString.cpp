void printSubsequence(string input, string output)
{
    // Base Case
    // if the input is empty print the output string
    if (input.empty()) {
        cout << output << endl;
        return;
    }
    cout<<"Input : "<<input<< " Output : "<<output<<endl;
    // output is passed with including
    // the Ist characther of
    // Input string
    printSubsequence(input.substr(1), output + input[0]);
 
    // output is passed without
    // including the Ist character
    // of Input string
    printSubsequence(input.substr(1), output);
}
 
// Driver code
int main()
{
    // output is set to null before passing in as a
    // parameter
    string output = "";
    string input = "abc";
 
    printSubsequence(input, output);
 
    return 0;
}