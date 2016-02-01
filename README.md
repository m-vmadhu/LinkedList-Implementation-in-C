# LinkedList-Implementation
Implementation of LinkedList using "C"

Created by: VasuMadhu

Following are the functions Defined in the LinkedList Program:
1. void main() - Main program to the function calls of a specific task
2. void create() - To create a singly linked list
3. void display() - This function will display the linked list
4. void insert_first() -To insert an element at the start of a Linked List
5. void insert_end() - To insert element at the end of the list
6. void insert_specific() - To insert element after a specific node position (Remember the program insert your element after the node position you enter as input)
7. void delete_specific() - To delete a specific element
8. void reverse() -To reverse the entire linked list and display the result

Best Practice: Dynamic program always serves best for conserving system's memory !!

Important points to note: 
1. we create a new node in the Heap memory using malloc() only when we require.
2. We delete a existing memory using free() when we no longer need it. 
(This is similar to the function of Garbage Collector in Java by dynamically cleaning the unused memory)
3. Create a unique structure of Node, to reuse the structure whenever creating new_node.
(This part resembles creating a class in Java)
4. Syntax for malloc:
  pointer = (data_type *)malloc(number_of_elements * sizeof(data_type))

Also, for reference I have included the comments whenever necessary in the LinkedList.c file

Have a nice day !

Tip:
If you did not get a logic right away don't worry,
try to work with the logic using a paper and pencil with your own values as input.

Best of Luck !




