class Apartment:
    def __init__(self, number, rent, squareFeet):
        self.number = number
        self.rent = rent
        self.squareFeet = squareFeet

    def __str__(self): # Defines how the object is as a string
        return f"Apartment {self.number} | Rent: ${self.rent:.2f} | Size: {self.squareFeet} sq ft"


class Stack:
    def __init__(self, capacity):
        self.capacity = capacity
        self.items = []
        self.top = -1 # Top element is at element 0 so -1 means there is no top element

    def isFull(self):
        return self.top == self.capacity - 1 # Top index of a full stack is capacity - 1 if true

    def isEmpty(self):
        return self.top == -1 # Means there are no elements in stack if true

    def push(self, apartment):
        if self.isFull():
            print(f"Cannot add {apartment}")
            return
        self.items.append(apartment)
        self.top += 1 # Updates index of top element in stack
        print(f"{apartment} pushed onto stack")

    def pop(self):
        if self.isEmpty():
            print("No apartments to pop")
            return None
        self.top -= 1 # Updates index of top element in stack
        return self.items.pop()

    def peek(self):
        if self.isEmpty():
            print("Stack is empty.")
            return None
        return self.items[self.top] # Gets top element of stack without removing it



if __name__ == "__main__":
    stack = Stack(3)

    a1 = Apartment(101, 1200.50, 750)
    a2 = Apartment(102, 1350.00, 800)
    a3 = Apartment(103, 1500.75, 900)

    # Checks before pushing
    print("Is stack empty?", stack.isEmpty())
    print("Is stack full?", stack.isFull())
    print("--------------------")

    stack.push(a1)
    stack.push(a2)
    stack.push(a3)

    # Checks after pushing
    print("Is stack empty?", stack.isEmpty())
    print("Is stack full?", stack.isFull())
    print("--------------------")

    print("Top apartment:", stack.peek()) # Last in, first out

    removed = stack.pop()
    print("Popped:", removed)

    # Checks after popping
    print("Is stack empty?", stack.isEmpty())
    print("Is stack full?", stack.isFull())
