# MicroSoft Interview Question
# Calculate difficulty of a given sentence. Here a Word is considered hard if it has 4 consecutive consonants or number of 
# consonants are more than number of vowels. Else word is easy.
# Difficulty of sentence is defined as 5*(number of hard words) + 3*(number of easy words).

def checkDifficulty():
  diff = 0
  easy = 0
  for i in (l):
    countv = 0
    countc = 0
    count_consecutive = 0
    for j in range(len(i)):
      if(i[j] == "a" or i[j] == "e" or i[j] == "i" or i[j] == "o" or i[j] == "u" ):
        count_consecutive = 0
        countv += 1
      else:
        count_consecutive += 1 
        countc += 1
      if(count_consecutive == 4):
        diff+=1
        break
    if(countc > countv):
      diff += 1
    else:
      easy += 1
  return 5 * diff + 3 * easy
  
s = input().lower()
l= (s.split())
ans = checkDifficulty()
print(ans)
