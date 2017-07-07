# Statement : Given a string of lowercase letters. Find minimum characters to be inserted in string so that it can become palindrome. 
#             We can change positions of characters in string.

# Approach : A palindromic string can have one odd character only when length of string is odd otherwise all characters occur even number 
#            of times. So, we have to find characters which occur odd times in a string.
#            The idea is to count occurrence of each character in a string. As palindromic string can have one character which occur odd 
#            times so number of insertion will be one less then count of characters which occur odd times. And if string is already 
#            palindrome, we do not need to add any character so result will be 0. 

def minInsertion():
  x = set(a)
  counter = 0
  for i in x:
    y = a.count(i)
    if(y % 2 != 0):
      counter+=1
  return counter - 1
    
a = input()
ans = minInsertion()
print(ans)
