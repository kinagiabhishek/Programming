shapes = {
  '1': 'CC', 
  '2': 'SS', 
  '3': 'TT',
  '4': 'CS',
  '5': 'CT',
  '6': 'ST',
}

def intro_msg():
    print('Welcome to THE FINAL SHAPE : VERITY Guardian!')

def mapper(symb):
    if symb=='C':
        return 'Circle'
    elif symb=='S':
        return 'Square'
    else :
        return 'Triangle'

def check_input_validity(s1,s2,s3):
    shapes_str = s1+s2+s3
    shapes_str = ''.join(sorted(shapes_str))
    if shapes_str.count('C')>2 or shapes_str.count('S')>2 or shapes_str.count('T')>2:
        return False
    else :
        return True
   
def user_inp():
    retList = []
    print('\nPlease enter inner symbols:\n')
    inpString = input()
    iLeft, iMiddle, iRight = inpString.split()
    retList.extend([iLeft, iMiddle, iRight])
    print('Please enter outer shapes:\n')
    print('1.Sphere 2.Cube 3.Pyramid 4.Cylinder 5.Cone 6.Prism\n')
    outString = input()
    print()
    oLeft, oMiddle, oRight = outString.split()
    retList.extend([shapes[oLeft], shapes[oMiddle], shapes[oRight]])
    return retList

def output_printer(shape_1, pos_1, shape_2, pos_2):
    print('Place '+mapper(shape_1)+' on '+pos_1+' and '+mapper(shape_2)+' on '+pos_2)

def dissect(s1, str1, s2, str2):
    str1=str1.replace(s1,"",1)
    str2=str2.replace(s2,"",1)
    str1+=s2
    str2+=s1
    str1=''.join(sorted(str1))
    str2=''.join(sorted(str2))
    return(str1,str2)
     
def solver(symbList):
    iLeft, iMiddle, iRight = symbList[0],symbList[1],symbList[2]
    oLeft, oMiddle, oRight = symbList[3],symbList[4],symbList[5]
    if check_input_validity(oLeft, oMiddle, oRight)!= True:
        print('Invalid User Input!\nTry Again')
        solver(user_inp())
        return
    
    if oLeft.count(iLeft) == 2 and oMiddle.count(iMiddle) == 2 and oRight.count(iRight): #Triple swap, break parity in left, middle
        oLeft, oMiddle = dissect(iLeft,oLeft,iMiddle,oMiddle)
        output_printer(iLeft,'Left',iMiddle,'Middle')
        oLeft, oRight = dissect(iLeft,oLeft,iRight,oRight)
        output_printer(iLeft,'Left',iRight,'Right')
        oMiddle,oRight = dissect(iMiddle,oMiddle,iRight,oRight)
        output_printer(iMiddle,'Middle',iRight,'Right')
    elif oLeft.count(iLeft) == 2:
        oLeft, oMiddle = dissect(iLeft,oLeft,iMiddle,oMiddle)
        output_printer(iLeft,'Left',iMiddle,'Middle')
        oLeft, oRight = dissect(iLeft,oLeft,iRight,oRight)
        output_printer(iLeft,'Left',iRight,'Right')   
    elif oMiddle.count(iMiddle) ==2:
        oLeft, oMiddle = dissect(iLeft,oLeft,iMiddle,oMiddle)
        output_printer(iLeft,'Left',iMiddle,'Middle')
        oMiddle,oRight = dissect(iMiddle,oMiddle,iRight,oRight)
        output_printer(iMiddle,'Middle',iRight,'Right')
    elif oRight.count(iRight) == 2:
        oLeft, oRight = dissect(iLeft,oLeft,iRight,oRight)
        output_printer(iLeft,'Left',iRight,'Right')
        oMiddle,oRight = dissect(iMiddle,oMiddle,iRight,oRight)
        output_printer(iMiddle,'Middle',iRight,'Right')
    elif iMiddle in oLeft:
        oLeft, oRight = dissect(iLeft,oLeft,iRight,oRight)
        output_printer(iLeft,'Left',iRight,'Right')
        oMiddle, oRight = dissect(iMiddle,oMiddle,iLeft,oRight)
        output_printer(iMiddle,'Middle',iLeft,'Right')
    elif iRight in oLeft:
        oLeft, oRight = dissect(iLeft,oLeft,iRight,oRight)
        output_printer(iLeft,'Left',iRight,'Right')
        oLeft, oMiddle = dissect(iRight,oLeft,iMiddle,oMiddle)
        output_printer(iRight,'Left',iMiddle,'Middle')
    else :
        print('Invalid User Input!\nTry Again')
        solver(user_inp())
       
intro_msg()
for i in range(3):
    solver(user_inp())

print('\nPlease any key to continue...')
enter_input = input()