#Checks a C++ file for plagiarism using GPT-3

#Reads C++ file
def read_file(filename):
    file = open(filename, "r")
    text = file.read()
    file.close()
    return text

#Asks user for file to check with GUI
