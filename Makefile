 # makefile for np

#### 頻繁に変更が必要なもの

#### 実装の関数群のオブジェクトファイル名 \ を書くと次の行も継続できる
# 1 行目に 田口雅将 が 2 行目に 滝沢 が 3 行目に 五十嵐碧唯 が書くことでコンフリクトを削減できる(4行目は\が要らない)
# 記述例
# OBJECTS = instruction.o add_a_im.o \
#                   mov_a_im.o \
#                   in b bin2int.o \
#                   led2str.o

#### 実装の関数群のオブジェクトファイル名 \ を書くと次の行も継続できる
# 1 行目は 4326 田口雅将 が記述
# 2 行目は 4325 滝澤 が記述
# 3 行目は 4305 五十嵐碧唯 が記述
OBJECTS= assignChar.o backupBoard.o boardTimeMachine.o displayWinner.o initStone.o\
         initBoard.o changeTurn.o initPlayer.o locatePlaceable.o locateOppStone.o prelocateOppStone.o locateOppStoneAround.o convertToCoodinate.o boardContent.o isSameOpporSiteStone.o insertToOpporSiteStone.o\
         blackAvailable.o changeStone.o whiteAvailable.o displayBoard.o inputStonePosition.o judgeGameSet.o\


#### テストの関数群のオブジェクトファイル名 \ を書くと次の行も継続できる
# 1 行目は 4326 田口雅将 が記述
# 2 行目は 4325 滝澤 が記述
# 3 行目は 4305 五十嵐碧唯 が記述
TEST_OBJECTS=testAssignChar.o testBackupBoard.o testBoardTimeMachine.o testDisplayWinner.o testInitStone.o\
         testInitBoard.o testChangeTurn.o testInitPlayer.o testLocatePlaceable.o testLocateOppStone.o testPrelocateOppStone.o testLocateOppStoneAround.o testConvertToCoodinate.o testBoardContent.o testIsSameOpporSiteStone.o testInsertToOpporSiteStone.o\
         testBlackAvailable.o testChangeStone.o testWhiteAvailable.o testDisplayBoard.o testInputStonePosition.o testJudgeGameSet.o\


#### UML から作りたい方の画像ファイルを記述
#PNGS= a.png
#SVGS= a.svg

# 最終実行ファイル(名前を修正したら .gitignore も修正すること)
TARGET=nipp

# テスト実行ファイル(名前を修正したら .gitignore も修正すること)
TEST_TARGET=testNipp


# curses / ncurses を使うか (どちらかを残す)
CURSES=on
#CURSES=off

#### 以下は変更する必要がないもの

.SUFFIXES: .uml .svg .png

.uml.png:
	plantuml $?; open $@

.uml.svg:
	plantuml -tsvg $?; open -a Safari $@

# 最終実行ファイルの実名
TARGET_EXE=$(TARGET)$(EXE)
# ターゲット実行ファイルの実名
TEST_TARGET_EXE=$(TEST_TARGET)$(EXE)
# 実装のためのヘッダー(プロトタイム宣言、構造体宣言、定数定義を含む)
HEADER=$(TARGET).h
# 実装のメインファイル main 関数を含む
MAIN=$(TARGET).o
# テストのためのヘッダー(プロトタイム宣言)
TEST_HEADER=$(TEST_TARGET).h
# テストのメインファイル main 関数を含む
TEST_MAIN=$(TEST_TARGET).o
# テストに必要なファイル
TEST_COMMON=testCommon.o
# 必要な CFLAGS
CFLAGS=-Wall -g
# 必要なライブラリ
LIBS=-lm

ifeq ($(OS),Windows_NT)
	CC=gcc
	RM=cmd.exe /C del
	EXE=.exe
else
	RM=rm -f
	EXE=
endif

ifeq ($(CURSES),on)
	ifeq ($(OS),Windows_NT)
		LIBS=-lncurses -lm
	else
		LIBS=-lncurses -lm
	endif
endif

exec: $(TARGET_EXE) $(PNGS) $(SVGS)
test: $(TEST_TARGET_EXE)

$(TARGET_EXE): $(MAIN) $(OBJECTS) $(HEADER)
	$(CC) -o $@ $(CFLAGS) $(MAIN) $(OBJECTS) $(LIBS)

$(TARGET_EXE): $(HEADER)

$(TEST_TARGET_EXE): $(TEST_MAIN) $(OBJECTS) $(TEST_OBJECTS) $(TEST_COMMON) $(HEADER) $(TEST_HEADER)
	$(CC) -o $@ $(CFLAGS) $(TEST_MAIN) $(OBJECTS) $(TEST_OBJECTS) $(TEST_COMMON) $(LIBS)

$(TEST_TARGET_EXE) : $(HEADER)

clean:
	$(RM) $(TARGET_EXE) $(TEST_TARGET_EXE) $(MAIN) $(TEST_MAIN) $(OBJECTS) $(TEST_OBJECTS) $(TEST_COMMON)
