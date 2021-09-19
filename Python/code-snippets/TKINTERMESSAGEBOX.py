import tkinter
import tkinter.messagebox
class MyGUI:
    def __init__(self):
        self.main_window = tkinter.Tk()
        self.top_frame=tkinter.Frame(self.main_window)
        self.bottom_frame = tkinter.Frame(self.main_window)
        self.my_button1=tkinter.Button(self.main_window, \
                                     text='Yes', \
                                     command = self.do_something)
        self.my_button2=tkinter.Button(self.main_window, \
                                     text='No', \
                                     command = self.do_something)
        self.label1=tkinter.Label(self.top_frame, \
                                  text='This Is It')
        self.label2= tkinter.Label(self.top_frame, \
                                   text = 'For')
        self.label3=tkinter.Label(self.top_frame, \
                                  text='GUI')
        self.label1.pack(side='top')
        self.label2.pack(side='top')

        self.label3.pack(side='top')
        self.label4=tkinter.Label(self.bottom_frame, \
                                  text='This is')
        self.label5= tkinter.Label(self.bottom_frame, \
                                   text = 'An')
        self.label6=tkinter.Label(self.bottom_frame, \
                                  text='Example')
        self.label4.pack(side='bottom')
        self.label5.pack(side='bottom')
        self.label6.pack(side='bottom')
        self.top_frame.pack()
        self.bottom_frame.pack()
        self.my_button1.pack(); self.my_button2.pack()
        tkinter.mainloop()
    def do_something(self):
        tkinter.messagebox.showinfo('Response', \
                                    'Your File Is Now Written.')
my_gui = MyGUI()
print(my_gui)
