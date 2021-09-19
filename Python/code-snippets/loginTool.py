#Connecting password with tkinter box
import tkinter
import tkinter.messagebox
password='glock_ht12'
class Login:
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
        else:
            tkinter.messagebox.showinfo('Invalid Entry...Please Try Again.')
passlog=Login()
print(passlog)
