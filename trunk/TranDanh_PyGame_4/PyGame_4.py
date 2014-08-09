import pygame
import Lib
import Global
#import os
scrWidth = 800
scrHeight = 600

mainArrBoard = []
for i in range(0, 9):
    mainArrBoard.append([])
    
for i in range(0, 9):
    for j in range(0, 9):
        mainArrBoard[i].append(1)
        
ArrBoard = []
for i in range(0, 9):
    ArrBoard.append([])
    
for i in range(0, 9):
    for j in range(0, 9):
        ArrBoard[i].append(1)

WHITE = (255, 255, 255)
RED   = (255, 0, 0)
BLUE  = (0, 0, 255)
BLACK = (0, 0, 0)
pygame.init()

surface = pygame.display.set_mode((scrWidth, scrHeight))
pygame.display.set_caption("The Fist Pygame")

clock = pygame.time.Clock()
isRun = True
isWin = False
isLose = False
Time = 100
FirstTick = pygame.time.get_ticks()
Lib.CreateBoard(ArrBoard)
print "BEGIN PyGame"
while isRun:    

    if Global.NumMatch == 4:
        isWin = True
    if (pygame.time.get_ticks() - FirstTick) / 1000 >= Time:
        isLose = True
    
    if isWin == False & isLose == False:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                isRun = False
            Lib.UpdateBoard(mainArrBoard, ArrBoard, event)    
        pygame.display.update()
        surface.fill(BLUE)    
        Lib.DrawBoard(surface, mainArrBoard)    
        Lib.DrawTime(surface, FirstTick, Time)
        pygame.display.flip()
        
    else:        
        if isWin == True:
            print "Win"
        if isLose == True:
            print "Lose"
        for event in pygame.event.get():
            if event.type == pygame.MOUSEBUTTONDOWN:
                isWin = False
                isLose = False
                FirstTick = pygame.time.get_ticks()
                for i in range(0, 9):
                    for j in range(0, 9):
                        mainArrBoard[i][j] = 1
                        ArrBoard[i][j] = 1
                Global.Last_i   =  -1
                Global.Last_j   =  -1
                Global.Cur_i    =  -1
                Global.Cur_j    =  -1
                Global.NumMatch =   0
                Lib.CreateBoard(ArrBoard)
                
    clock.tick(60)
    
pygame.quit()
















