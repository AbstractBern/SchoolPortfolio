import tkinter
import tkinter.messagebox
def main():
    entrance()
def entrance():
    password='iCowboy15'
    class Window:
            def __init__(self):
                self.main_window=tkinter.Tk()
                self.top_frame=tkinter.Frame(self.main_window)
                self.bottom_frame=tkinter.Frame(self.main_window)

                self.prompt_label = tkinter.Label(self.top_frame, \
                                                  text='ENTER A PASSWORD:')
                self.password_entry = tkinter.Entry(self.top_frame, \
                                                    width=15)
                self.prompt_label.pack(side='left')
                self.password_entry.pack(side='left')
                self.enter_button=tkinter.Button(self.bottom_frame, \
                                                 text='Enter', \
                                                 command=self.enter)
                self.quit_button=tkinter.Button(self.bottom_frame, \
                                                text='Quit', \
                                                command=self.main_window.destroy)
                self.enter_button.pack(side='left')
                self.quit_button.pack(side='left')
                self.top_frame.pack()
                self.bottom_frame.pack()
                tkinter.mainloop()
            def enter(self):
                entry =self.password_entry.get()
                if entry == password:
                    tkinter.messagebox.showinfo('Valid Entry', \
                                                'Continuing...')
                    def open_file():
                        import pickle
                        end_of_file=False
                        try:
                            output_file=open('Info-Note.dat','rb')
                            while not end_of_file:
                                content=pickle.load(output_file)
                                print(content)
                        except EOFError:
                            end_of_file=True
                    open_file()
                else:
                    tkinter.messagebox.showinfo('Invalid Entry', \
                                                'Please Try Again.')
    attempt=Window()
    print(attempt)
    
main()
input()
