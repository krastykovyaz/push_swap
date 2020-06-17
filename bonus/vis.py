import cmd, sys, subprocess, time
import tkinter as tk

argv = sys.argv[1:]
if (len(argv) > 200):
    print("It is not an error:)\n")
    print ("Try to use less than 200 numbers, cause that will be more representative!")
    exit()
for i in range(0, len(argv)):
    argv[i] = int(argv[i])
myList = list(range(1, (len(argv) + 1)))
arr_sort = sorted(argv)
init_ind_arr = [myList[arr_sort.index(i)] for i in argv]
st_a = init_ind_arr
st_b = []

width = 1000
height = 500
master = tk.Tk()
master.title('push_swap')
master.resizable(width=False, height=False)
canvas = tk.Canvas(master, bg='black', height= height, width = width)
canvas.pack()

number = height / len(argv)
distribution = ((width - 10) / 2) / myList[-1]

def set_color(i, arr):
        if i < len(st_a) / 3:
            return "white"
        elif i > len(st_a) / 3 and i < (len(st_a) * 2 / 3):
            return "blue"
        else:
            return "red"

def stack_a(st_a):
    for i in range(len(st_a)):
        canvas.create_rectangle(0, i * number, st_a[i] * distribution, (i + 1) * number, fill=set_color(st_a[i], st_a))

def stack_b(st_a):
    for i in range(len(st_a)):
        canvas.create_rectangle(width / 2, i * number, (st_a[i] * distribution) + width / 2, (i + 1) * number, fill="gray")

stack_a(st_a)
stack_b(st_b)


operations = subprocess.check_output(["./push_swap"] + sys.argv[1:], stderr=subprocess.STDOUT).splitlines()
print(operations)
canvas.update()
time.sleep(1)
canvas.delete("all")

def s(arr):
    arr[0], arr[1] = arr[1], arr[0]
    return(arr)
def r(arr):
    arr.append(arr[0])
    del arr[0]
    return(arr)
def rr(arr):
    arr = [arr[-1]] + arr
    del arr[-1]
    return(arr)
def p(arr1, arr2):
    arr2 = [arr1[0]] + arr2
    del arr1[0]
    return(arr1, arr2)
def pause(st_a, st_b):
    stack_a(st_a)
    stack_b(st_b)
    canvas.update()
    time.sleep(0.01)
    canvas.delete("all")

for i in operations:
    if i == b'sa':
        st_a = s(st_a)
        pause(st_a, st_b)
    elif i == b'ra':
        st_a = r(st_a)
        pause(st_a, st_b)
    elif i == b'rra':
        st_a = rr(st_a)
        pause(st_a, st_b)
    elif i == b'pb':
        st_a, st_b = p(st_a, st_b)
        pause(st_a, st_b)
    elif i == b'pa':
        st_b, st_a = p(st_b, st_a)
        pause(st_a, st_b)
    elif i == b'sb':
        st_b = s(st_b)
        pause(st_a, st_b)
    elif i == b'rb':
        st_b = r(st_b)
        pause(st_a, st_b)
    elif i == b'rrb':
        st_b = rr(st_b)
        pause(st_a, st_b)

stack_a(st_a)
stack_b(st_b)

master.mainloop()
