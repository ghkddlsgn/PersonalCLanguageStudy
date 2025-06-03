my_set = {1,2,3,4,5}
print(my_set)
print(type(my_set))

my_empty_set = set([1,2,3,4,5,6])
print(my_empty_set)

#basic set operation
#adding and removing elem
my_set.add(7)
print(my_set)

#remove elem from set
my_set.remove(2)
print(my_set)

my_set.discard(11)

#pop method
remove_element = my_set.pop()
print(remove_element)
print(my_set)

#clear all the elements
my_set.clear()
print(my_set)

#set membership test
my_set = {1,2,3,4,5}
print(3 in my_set)
print(10 in my_set)

#math operation
set1 = {1,2,3,4,5}
set2 = {4,5,6,7,8,9}

#union
union_set = set1.union(set2)
print(union_set)

#intersetction
intersection_set = set1.intersection(set2)
print(intersection_set)

set1.intersection_update(set2)
print(set1)

#difference
set1 = {1,2,3,4,5,6}
set2 = {4,5,6,7,8,9}

print(set1.difference(set2))

#symmetric difference
print(set1.symmetric_difference(set2))

#sets methods
set1={1,2,3}
set2={3,4,5}

#is subset
print(set1.issubset(set2))
print(set1.issuperset(set2))

#counting unique words in text
text = "In this tutorial we are discussing about sets"
words = text.split()
words = set(words)
print(words)
print(len(words))