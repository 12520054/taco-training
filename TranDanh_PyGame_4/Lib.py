#Draw Board
import random
import pygame
import Global


def CreateBoard(ArrBoard):
    match = 0
    iCur = -1
    jCur = -1
    iLast = -1
    jLast = -1
    while match != 40:
        iCur = random.randint(0, 8)
        jCur = random.randint(0, 8)
        if ArrBoard[iCur][jCur] == 1:
                    ArrBoard[iCur][jCur] = random.randint(2, 5)
                    if iLast == -1 and jLast == -1:
                            iLast = iCur
                            jLast = jCur
                    else:
                        if ArrBoard[iCur][jCur] != ArrBoard[iLast][jLast]:
                            ArrBoard[iCur][jCur] = 1
                            ArrBoard[iLast][jLast] = 1
                        else:
                            match += 1
                        iLast = -1
                        jLast = -1                
    pass

class Square():
    def __init__(self, tplPosition, tplColor, status):
        self.mTplPosition = tplPosition
        self.mTplColor = tplColor
        self.mIntStatus = status
        pass
    def Draw(self, surface):
        pygame.draw.rect(surface, self.mTplColor, self.mTplPosition, self.mIntStatus)
        pass



#Update Board
def UpdateBoard(mainArrBoard, ArrBoard, MouseEvent):
    if MouseEvent.type == pygame.MOUSEBUTTONDOWN:
        if MouseEvent.pos[0] > 50 and MouseEvent.pos[0] < 500:
            if MouseEvent.pos[1] > 50 and MouseEvent.pos[1] < 500:
                Global.Cur_i = (MouseEvent.pos[0] / 50) - 1
                Global.Cur_j = (MouseEvent.pos[1] / 50) - 1
                if mainArrBoard[Global.Cur_i][Global.Cur_j] == 1:
                    mainArrBoard[Global.Cur_i][Global.Cur_j] = ArrBoard[Global.Cur_i][Global.Cur_j]
                    if Global.Last_i == -1 and Global.Last_j == -1:
                        Global.Last_i = Global.Cur_i
                        Global.Last_j = Global.Cur_j
                    else:
                        if mainArrBoard[Global.Cur_i][Global.Cur_j] != mainArrBoard[Global.Last_i][Global.Last_j]:
                            mainArrBoard[Global.Cur_i][Global.Cur_j] = 1
                            mainArrBoard[Global.Last_i][Global.Last_j] = 1
                        else:
                            Global.NumMatch += 1
                        Global.Last_i = -1
                        Global.Last_j = -1
    pass





#Draw Board
def DrawBoard(surface, mainArrBoard):
    
    for i in range(0, 9):
        for j in range(0, 9):
            if mainArrBoard[i][j] == 1:
                s = Square((50 + i*50,50 + j*50, 50, 50), (255, 255, 255), 1)
                s.Draw(surface)
            if mainArrBoard[i][j] == 2:
                s = Square((50 + i*50,50 + j*50, 50, 50), (255, 255, 255), 0)
                s.Draw(surface)
            if mainArrBoard[i][j] == 3:
                s = Square((50 + i*50,50 + j*50, 50, 50), (255, 255, 0), 0)
                s.Draw(surface)
            if mainArrBoard[i][j] == 4:
                s = Square((50 + i*50,50 + j*50, 50, 50), (255, 0, 255), 0)
                s.Draw(surface)
            if mainArrBoard[i][j] == 5:
                s = Square((50 + i*50,50 + j*50, 50, 50), (0, 255, 255), 0)
                s.Draw(surface)
    pass

#Draw Time
R_1 = (50, 0, 0)
R_2 = (100, 0, 0)
R_3 = (150, 0, 0)
R_4 = (200, 0, 0)
R_5 = (255, 0, 0)

def DrawTime(surface, FirstTick, Time):
    PixelPerSec = 450 / Time;
    TotalTime   = (pygame.time.get_ticks() - FirstTick) / 1000
    FirstTime   = Time / 5;
    SecondTime  = 2*FirstTime
    ThirdTime   = 3*FirstTime
    FourTime    = 4*FirstTime
    if TotalTime < FirstTime:
        pygame.draw.rect(surface, R_1, (600, 50 + TotalTime*PixelPerSec, 50, 90 - TotalTime*PixelPerSec))
        pygame.draw.rect(surface, R_2, (600, 50 + 90  , 50, 90))
        pygame.draw.rect(surface, R_3, (600, 50 + 90*2, 50, 90))
        pygame.draw.rect(surface, R_4, (600, 50 + 90*3, 50, 90))
        pygame.draw.rect(surface, R_5, (600, 50 + 90*4, 50, 90))
        pass
    if (TotalTime < SecondTime) & (TotalTime >= FirstTime):
        pygame.draw.rect(surface, R_2, (600, 50 + TotalTime*PixelPerSec, 50, 180 -  TotalTime*PixelPerSec))
        pygame.draw.rect(surface, R_3, (600, 50 + 90*2, 50, 90))
        pygame.draw.rect(surface, R_4, (600, 50 + 90*3, 50, 90))
        pygame.draw.rect(surface, R_5, (600, 50 + 90*4, 50, 90))
        pass
    if (TotalTime < ThirdTime) & (TotalTime >= SecondTime):
        pygame.draw.rect(surface, R_3, (600, 50 + TotalTime*PixelPerSec, 50, 270 -  TotalTime*PixelPerSec))
        pygame.draw.rect(surface, R_4, (600, 50 + 90*3, 50, 90))
        pygame.draw.rect(surface, R_5, (600, 50 + 90*4, 50, 90))
        pass 
    if (TotalTime < FourTime) & (TotalTime >= ThirdTime):
        pygame.draw.rect(surface, R_4, (600, 50 + TotalTime*PixelPerSec, 50, 360 - TotalTime*PixelPerSec))
        pygame.draw.rect(surface, R_5, (600, 50 + 90*4, 50, 90))
        pass 
    if (TotalTime < Time) & (TotalTime >= FourTime):
        pygame.draw.rect(surface, R_5, (600, 50 + TotalTime*PixelPerSec, 50, 450 - TotalTime*PixelPerSec))
    pass