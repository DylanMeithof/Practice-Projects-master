# python 3.10.2 | Robotics Debug Terminal | 2/17/22
i = 1

def Action_Loop():
    i = 0
    task_search = input("Enter Action: ")

    if task_search == "help" :
        print("Available Commands: open, ...")
    # Error Reports | Code Search | Auto Fix | Variable Search
    elif task_search == "open" :
        file_name = input("Enter File Name: ")
        with open(file_name + '.java') as f:
            lines = f.read()
            print(lines)
        kill_program = input("")

while i == 1: 
    Action_Loop()