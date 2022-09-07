#HW1 Justin Reini
#Objective: make calculations using roman numerals
import re #importing regex used for checking for correct format of the input

romNums = ['M','D','C','L','X','V','I']  #all possible roman numerals

#Dictionaries of translated values in order to account for translation during calculations later

ExpandVals = {"V" : "IIIII", "X" : "VV", "L" : "XXXXX", "C" : "LL", "D" : "CCCCC", "M" : "DD"}
SubVals = {"IV" : "IIII", "IX" : "VIIII", "XL" : "XXXX", "XC" : "LXXXX", "CD" : "CCCC", "CM" : "DCCCC"}

def formatcheck(romnum):  #first function: checks to make sure the input is formatted correctly
    valid_format = False
    correct_format = "^M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$" #checks for valid roman numerals
    valid_format = re.match(correct_format, romnum)  #uses regex to make sure the input is correctly formatted 
    return valid_format

def validcheck(romnum): #boolean function that checks if input is all roman numerals
    valid_input = False
    while (not valid_input):
        for char in romnum:
            if char in romNums:
                valid_input = True
            else:
                valid_input = False
                break

        if valid_input:
            valid_input = formatcheck(romnum) #check to make sure the input is formatted correctly

        return valid_input #return either True or False

def romnumAdd(num1, num2):
    for subval in SubVals.keys():
        #Expand the numbers to begin
        num1 = num1.replace(subval, SubVals[subval])
        num2 = num2.replace(subval, SubVals[subval])
        
    join = num1 + num2 #concatenate
    answer = "" 
    for numeral in romNums:
        for char in join:
            if char == numeral:
                answer += char #sort the numerals in the correct order
    
    for expandval in ExpandVals.keys(): #compacts values where needed in the answer
        answer = answer.replace(ExpandVals[expandval], expandval)
    for subval in SubVals.keys(): #expands values where needed in the answer
        answer = answer.replace(SubVals[subval], subval)
    return answer

def romnumSub(num1, num2):  #This function deals with subtraction
    for subval in SubVals.keys():
        #Expand the numbers to begin
        num1 = num1.replace(subval, SubVals[subval])
        num2 = num2.replace(subval, SubVals[subval])

    for numeral in num2: #gets rid of any like symbols between num1 and num2
        if numeral in num1:
            num1 = num1.replace(numeral, '', 1)
            num2 = num2.replace(numeral, '', 1)
            #replaces the same numeral with empty string

    if (len(num2) > len(num1)):
            print('Trying to subtract a larger number from a smaller number!')
            exit()

    if (len(num2) == 0): #if no characters left, return the answer
        answer = num1
        return answer

    else: #else, replace all numerals with I and get rid of like symbols
        for numeral in romNums[:6]:
            num1 = num1.replace(numeral, ExpandVals[numeral])
            num2 = num2.replace(numeral, ExpandVals[numeral])
        
        for char in num2: 
            if char in num1:
                num1 = num1.replace(char, '', 1)
                num2 = num2.replace(char, '', 1)

        if (len(num2) > len(num1)):
            print('Trying to subtract a larger number from a smaller number!')
            exit()

    answer = num1 #num1 will be the answer

    for expandval in ExpandVals.keys(): #compacts values where needed in the answer
        answer = answer.replace(ExpandVals[expandval], expandval)
    for subval in SubVals.keys(): #expands values where needed in the answer
        answer = answer.replace(SubVals[subval], subval)
    return answer



#Main
def main():
    term_list = []
    operations_list = []
    num_inputs = input("Enter the amount of terms you want to add or subtract: ")
    if num_inputs.isdigit(): #makes sure its a digit
        num_inputs = int(num_inputs)
    else:
        num_inputs = 0

    for inp in range(num_inputs): #enter each term and make sure its valid
        valid_input = False
        while (not valid_input):
            num = input("Enter the term: ")
            if (not validcheck(num)): #if invalid, give message
                print("The number you've entered is invalid, Try again.")
            else: #if valid, add to list of terms
                valid_input = True
                term_list.append(num) 

        if inp < num_inputs - 1: #makes sure theres no operation after last term
            valid_operator = False
            while (not valid_operator): 
                op = input("Enter operation type (either + or -): ")
                if op == '+' or op == '-':
                    valid_operator = True
                    operations_list.append(op)
                else:
                    print("Invalid operator. The operator must be either + or -")

    num_terms = len(term_list)
    for term in range(num_terms - 1): #go through each addition or subtraction 
        num1 = term_list.pop(0)
        num2 = term_list.pop(0)
        op = operations_list.pop(0) 

        if op == '+':
            curr_sum = romnumAdd(num1, num2)
        else:
            curr_sum = romnumSub(num1, num2)

        term_list.insert(0, curr_sum) #add the current sum back into the list

    final_sum = term_list[0] #the final sum will be the first one
    print("\nFinal answer:")
    if final_sum=='':
        print("No answer")
    else:
        print(final_sum)



if __name__ == '__main__':
    main()
