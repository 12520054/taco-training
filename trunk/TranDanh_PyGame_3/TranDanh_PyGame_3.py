class Student():
    def __init__(self):
        self.m_Name = ""
        self.m_Dob = ""
        self.m_ID = ""
        self.m_Faculty = ""
        pass
    def InputInfo(self):
        s = raw_input()
        values = s.split("\" \"")
        self.m_Name = values[0][1:len(values[0])]
        self.m_Dob = values[1]
        self.m_ID = values[2]
        self.m_Faculty = values[3][0:len(values[3]) - 1]
        pass
    def Print(self):
        print "Name: "+self.m_Name, "DOB: " + self.m_Dob,"ID: " +  self.m_ID,"ID: " + self.m_Faculty
        pass
    def SaveInfo(self):
        try:
            with open("students.stdiodb", "r") as f:
                for line in f.readlines():
                    values = line.split("\"")
                    if self.m_ID == values[5]:
                        print "Can't insert this ID Student."
                        return
        except:
            print "Can't open this file\n"
        try:
            with open("students.stdiodb", "a") as sfile:
                string = "name=\"" + self.m_Name + "\"dob=\"" + self.m_Dob + "\"sid=\"" + self.m_ID + "\"faculty=\"" + self.m_Faculty + "\"\n"
                sfile.write(string)
        except:
            print "Can't open this File\n"
        pass
def PrintListStudent():
    k = 1
    f = open("students.stdiodb", "r")
    if f == False:
        return
    for line in f.readlines():
        values = line.split("\"")
        Name = values[1]
        Dob = values[3]
        ID = values[5]
        Faculty = values[7]
        sline = "Name: "+Name+" | "+"BirthDay: "+Dob+" | "+"Student ID: "+ID+" | "+"Faculty: "+Faculty
        print str(k) + '. ' + sline
        k += 1
    f.close()
    pass

def PrintMenu():
    print '---[students.stdiodb]---'
    print '1. List all students'
    print '2. Add new student'
    print '3. Edit student'
    print '4. Delete student'
    print '5. Quit'
    pass 
def EditInfo(ID):
    f = open("Templ.txt", "w") 
    sf = open("students.stdiodb", "r")
    i = 0
    for line in sf.readlines():
        values = line.split("\"")
        if ID == values[5]:
            i += 1
            st = Student()
            st.InputInfo()
            string = "name=\"" + st.m_Name + "\"dob=\"" + st.m_Dob + "\"sid=\"" + st.m_ID + "\"faculty=\"" + st.m_Faculty + "\"\n"
            f.write(string)
        else:
            f.write(line)
    if i == 0:
        print "can't find this Student"
    f.close()
    sf.close()
    f = open("Templ.txt", "r")
    sf = open("students.stdiodb", "w")
    for line in f.readlines():
        sf.write(line)
    f.close()
    sf.close()
    import os
    os.remove("Templ.txt")
    pass
def DeleteStudent(ID):
    f = open("Templ.txt", "w") 
    sf = open("students.stdiodb", "r")
    i = 0
    for line in sf.readlines():
        values = line.split("\"")
        if ID == values[5]:
            i += 1
        else:
            f.write(line)
    if i == 0:
        print "can't find this Student\n"
    f.close()
    sf.close()
    f = open("Templ.txt", "r")
    sf = open("students.stdiodb", "w")
    for line in f.readlines():
        sf.write(line)
    f.close()
    sf.close()
    import os
    os.remove("Templ.txt")
    pass


#>>> My program
IsLoop = True
k = 0

student = Student()
while IsLoop == True:
    import os
    os.system('cls')
    PrintMenu()
    k = input('Select Option: ')
    if k == 1:
        PrintListStudent()
    if k == 2:
        student.InputInfo()
        student.SaveInfo()
    if k == 3:
        ID = input("ID: ")
        EditInfo(ID)
    if k == 4:
        ID = input("ID: ")
        DeleteStudent(ID)
    if k == 5:
        print 'Exiting....'
        IsLoop = False
