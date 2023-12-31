import random
import tkinter as tk
from tkinter import messagebox

class SimpleApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Dice Roller App - Rezky (2241018)")

        self.total = 0
        self.correct1 = 0
        self.correct2 = 0
        self.correct3 = 0
        self.wrong1 = 0
        self.wrong2 = 0
        self.wrong3 = 0

        # create a dice list
        self.my_dice = ('\u2680', '\u2681', '\u2682', '\u2683', '\u2684', '\u2685')

        # Create menu bar
        menubar = tk.Menu(root)

        # Option 1 menu
        option1_menu = tk.Menu(menubar, tearoff=0)
        option1_menu.add_command(label="...", command=lambda: self.show_frame("red"))
        option1_menu.add_command(label="Exit", command=lambda: self.root.destroy())
        menubar.add_cascade(label="File", menu=option1_menu)

        # Option 2 menu
        option2_menu = tk.Menu(menubar, tearoff=0)
        option2_menu.add_command(label="Big/Small Guess", command=lambda: self.show_frame("blue"))
        option2_menu.add_command(label="Number Guess", command=lambda: self.show_frame("orange"))
        option2_menu.add_command(label="Time Attack", command=lambda: self.show_frame("green"))
        menubar.add_cascade(label="Mode", menu=option2_menu)

        root.config(menu=menubar)

        # Create frames
        self.frames = {}

        # Red frame
        red_frame = tk.Frame(root, bg="red")
        self.frames["red"] = red_frame

        # Add label to the red frame
        label_red = tk.Label(red_frame, text="This is the red Frame")
        label_red.grid(row=0, column=0, pady=10)

        # Add button to the red frame
        button_red = tk.Button(red_frame, text="Click me in red frame", command=lambda: self.on_button_click("red"))
        button_red.grid(row=1, column=0, pady=20)

        # Blue frame
        blue_frame = tk.Frame(root, bg="blue")
        self.frames["blue"] = blue_frame

        # create dice labels
        self.label_blue_title = tk.Label(blue_frame, text='Big/Small Guess Mode', font=("Helvetica", 24))
        self.label_blue_title.grid(row=0, column=0, pady=10)

        # create dice labels
        self.label_blue_dice = tk.Label(blue_frame, text='\u2680', font=("Helvetica", 100), fg="black")
        self.label_blue_dice.grid(row=1, column=0, pady=10, padx=240)

        # create information label
        self.label_big_small = tk.Label(blue_frame, text='Guess the next number!', font=("Helvetica", 14))
        self.label_big_small.grid(row=2, column=0, pady=10)

        # create big small button
        big_button = tk.Button(blue_frame, text="Big (4-6)", font=("Helvetica", 12), command=lambda: self.big_small_roll("big"))
        small_button = tk.Button(blue_frame, text="Small (1-3)", font=("Helvetica", 12), command=lambda: self.big_small_roll("small"))

        small_button.grid(row=3, column=0, pady=10)
        big_button.grid(row=4, column=0, pady=10)

        self.label_score_big_small1 = tk.Label(blue_frame, text="Correct: ")
        self.label_score_big_small2 = tk.Label(blue_frame, text="Wrong: ")

        self.label_score_big_small1.grid(row=5, column=0, pady=10)
        self.label_score_big_small2.grid(row=6, column=0, pady=10)

        # Orange frame
        orange_frame = tk.Frame(root, bg="orange")
        self.frames["orange"] = orange_frame

        # create dice labels
        self.label_orange_title = tk.Label(orange_frame, text='Guess Number Mode', font=("Helvetica", 24))
        self.label_orange_title.grid(row=0, column=1, pady=10)

        # create dice labels
        self.label_orange_dice = tk.Label(orange_frame, text='\u2680', font=("Helvetica", 100), fg="black")
        self.label_orange_dice.grid(row=1, column=1, pady=10, padx=105)

        # create information label
        self.label_guess_number = tk.Label(orange_frame, text='Guess the next number!', font=("Helvetica", 14))
        self.label_guess_number.grid(row=2, column=1, pady=10)

        # create number button
        button_guess_1 = tk.Button(orange_frame, text="1", font=("Helvetica", 12), command=lambda: self.number_guess_roll(1))
        button_guess_2 = tk.Button(orange_frame, text="2", font=("Helvetica", 12), command=lambda: self.number_guess_roll(2))
        button_guess_3 = tk.Button(orange_frame, text="3", font=("Helvetica", 12), command=lambda: self.number_guess_roll(3))
        button_guess_4 = tk.Button(orange_frame, text="4", font=("Helvetica", 12), command=lambda: self.number_guess_roll(4))
        button_guess_5 = tk.Button(orange_frame, text="5", font=("Helvetica", 12), command=lambda: self.number_guess_roll(5))
        button_guess_6 = tk.Button(orange_frame, text="6", font=("Helvetica", 12), command=lambda: self.number_guess_roll(6))

        button_guess_1.grid(row=3, column=1)
        button_guess_2.grid(row=4, column=1)
        button_guess_3.grid(row=5, column=1)
        button_guess_4.grid(row=6, column=1)
        button_guess_5.grid(row=7, column=1)
        button_guess_6.grid(row=8, column=1)

        self.label_score_number_guess1 = tk.Label(orange_frame, text="Correct: ")
        self.label_score_number_guess2 = tk.Label(orange_frame, text="Wrong: ")

        self.label_score_number_guess1.grid(row=1, column=0, pady=20, padx=40)
        self.label_score_number_guess2.grid(row=1, column=2, pady=20, padx=40)

        # Green frame
        green_frame = tk.Frame(root, bg="green")
        self.frames["green"] = green_frame

        # create dice labels
        self.label_green_title = tk.Label(green_frame, text='Time Attack Mode', font=("Helvetica", 24))
        self.label_green_title.grid(row=0, column=0, pady=10)
        
        # create dice labels
        self.label_green_dice = tk.Label(green_frame, text='\u2680', font=("Helvetica", 100), fg="black")
        self.label_green_dice.grid(row=1, column=0, pady=10, padx=240)

        # Add label to the green frame
        self.label_green = tk.Label(green_frame, text="0")
        self.label_green.grid(row=2, column=0, pady=10)

        self.main_button = tk.Button(green_frame, text="Click Me!", command=self.time_attack_roll, state=tk.DISABLED)
        self.main_button.grid(row=3, column=0, pady=20)

        self.start_button = tk.Button(green_frame, text="Start Timer", command=self.start_timer)
        self.start_button.grid(row=4, column=0, pady=10)

        # Show one of the frames initially
        self.show_frame("blue")

        # Configure row and column to center the frames
        # for frame in self.frames.values():
            # frame.grid_rowconfigure(0, weight=1)
            # frame.grid_columnconfigure(0, weight=1)

    def start_timer(self):
        self.main_button.config(state=tk.NORMAL)
        self.label_green.config(text="0")
        self.remaining_time = 5
        self.update_timer()

    def stop_timer(self):
        if self.timer_id:
            self.root.after_cancel(self.timer_id)
            self.timer_id = None
        self.main_button.config(state=tk.DISABLED)

    def update_timer(self):
        if self.remaining_time > 0:
            self.main_button.config(state=tk.NORMAL)
            self.remaining_time -= 1
            self.timer_id = self.root.after(1000, self.update_timer)
        else:
            self.main_button.config(state=tk.DISABLED)
            self.timer_id = None

    def show_frame(self, color):
        for frame in self.frames.values():
            frame.grid_forget()
        self.frames[color].grid(row=0, column=0, sticky="nsew")

    def on_button_click(self, color):
        print(f"Button clicked in {color} frame")

    def get_number(self, x):
        if x == '\u2680':
            return(1)
        elif x == '\u2681':
            return(2)
        elif x == '\u2682':
            return(3)
        elif x == '\u2683':
            return(4)
        elif x == '\u2684':
            return(5)
        elif x == '\u2685':
            return(6)

    def roll_dice(self):
        d1 = random.choice(self.my_dice)
        sd1 = self.get_number(d1)
        self.label_dice.config(text=d1)

    def big_small_roll(self, guess):
        d1 = random.choice(self.my_dice)
        sd1 = self.get_number(d1)
        self.label_blue_dice.config(text=d1)
        
        if (sd1 <= 3):
            if (guess == "small"):
                messagebox.showinfo("Information", f"Is {sd1} a small number? Correct!")
                self.correct1 += 1
                self.label_score_big_small1.config(text=f"Correct: {self.correct1}")
            elif (guess == "big"):
                messagebox.showinfo("Information", f"Is {sd1} a big number? Wrong!")
                self.wrong1 += 1
                self.label_score_big_small2.config(text=f"Wrong: {self.wrong1}")
        elif (sd1 >= 4):
            if (guess == "small"):
                messagebox.showinfo("Information", f"Is {sd1} a small number? Wrong!")
                self.wrong1 += 1
                self.label_score_big_small2.config(text=f"Wrong: {self.wrong1}")
            elif (guess == "big"):
                messagebox.showinfo("Information", f"Is {sd1} a big number? Correct!")
                self.correct1 += 1
                self.label_score_big_small1.config(text=f"Correct: {self.correct1}")

    def number_guess_roll(self, guess):
        d1 = random.choice(self.my_dice)
        sd1 = self.get_number(d1)
        self.label_orange_dice.config(text=d1)
        
        if (sd1 == guess):
            messagebox.showinfo("Information", f"Your answer is {guess}, correct!")
            self.correct2 += 1
            self.label_score_number_guess1.config(text=f"Correct: {self.correct2}")
        else:
            messagebox.showinfo("Information", f"Your answer is {guess}, wrong!")
            self.wrong2 += 1
            self.label_score_number_guess2.config(text=f"Wrong: {self.wrong2}")

    def time_attack_roll(self):
        d1 = random.choice(self.my_dice)
        sd1 = self.get_number(d1)
        self.total += sd1
        self.label_green_dice.config(text=d1)
        self.label_green.config(text=f"{self.total}")

if __name__ == "__main__":
    root = tk.Tk()
    app = SimpleApp(root)
    root.geometry("600x500")
    root.mainloop()
