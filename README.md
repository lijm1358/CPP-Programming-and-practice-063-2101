# CPP-Programming-and-practice-063-2101
## class LectureHandler
* ### 멤버변수 목록
  * <code>Lecture* lectureList</code> : Lecture들을 저장할 수 있는 배열
  * <code>int lectureCount</code> : lectureList에 저장되어있는 lecture들의 수
  * <code>static int lectureCodeSequence</code> : lecture를 추가할 때 마다, 설정할 강의 코드. 1부터 시작하여 추가할 때 마다 1씩 늘어남.
* ### 멤버함수 목록
  * <code>void addLecture(professor&)</code> : lectureList에 강의 추가.  반환값 없이 함수 내에서 모든 동작 처리. professor클래스를 받아서, 해당 클래스의 멤버변수 char* name에 저장되어있는 교수명을, Lecture 클래스의 교수명에 저장.
  * <code>void showAllLecture() const</code> : lectureList에 있는 모든 강의들에 대한 정보 출력
  * <code>void changeLectureInfo()(Lecture&)</code> : Lecture 클래스 인스턴스를 받아서, 해당 lecture의 정보 변경. 변경할 정보 등의 선택은 함수 내에서 이루어짐.
  * <code>Lecture* findLecture(int) const</code> : 강의코드를 받아서, 해당 강의코드와 일차하는 lecture 클래스 반환. 일치하는 강의가 없으면 NULL반환.
  * <code>Lecture* findLecture(char*) const</code> : 강의명을 받아서, 해당 강의명과 일치하는 lecture 클래스 반환. 일치하는 강의가 없으면 NULL반환. 
  * <code>void showLectureByProfName(char*) const;</code> : 교수명을 받아서, 해당 교수명과 일치하는 강의들을 출력.
  * <code>int getLectureCount() const;</code> : 현재 저장된 강의 갯수 반환
-------
## function.cpp
### main()에서 호출될 함수들 목록
* ### 함수 목록
  * <code>AddLecture(LectureHandler& lectHdl, professor& prof)</code> : 강의 추가
  * <code>ShowAllLecture(LectureHandler& lectHdl)</code> : 모든 강의 정보 출력
  * <code>AddGrade(LectureHandler& lectHdl, UserHandler& userHdl, professor& prof)</code> : 인자로 전달받은 professor클래스가 생성한 강의, 전체 강의 목록, 전체 사용자 목록 등의 정보를 이용해 학생들의 성적 등록.
------
## etc
* ### comn_exception 
  * <code>class consoleInputFailException</code> : cin.fail()시, throw할 exception class. 멤버함수로 오류 메세지를 출력하는 <code>showExceptionMessage()</code>, 입력 버퍼를 초기화하는 clearBuffer()함수 존재.
* ### LectureHandler :: class TimeInputException, checkTimeStringFormat()
* ##### LectureHandler::addLecture및 LectureHandler::changeLectureInfo에서 강의 시간을 입력받을 때, 입력받은 강의 시간의 형식이 올바른지(24시간, HHMM~HHMM)에 대한 처리를 담당하는 예외 클래스 및 함수
  * <code>checkTimeStringFormat(string time)</code> : 입력받은 시간 형식이 올바른지 검사하는 함수. 올바르지 않으면 오류 상황에 따라 아래의 예의 클래스를 throw
  * <code>virtual void showExceptionMessage() const = 0</code> : 자식 클래스들에서 사용할 showExceptionMessage를 부모 클래스에서 구현만 한 것(virtual 및 = 0 사용).
  * <code>class WrongTimeFormatException</code> : ~를 사용하지 않았거나, 문자열의 길이가 맞지 않는 등 입력 형식이 틀렸을 때 발생시킬 예외
  * <code>class InvalidTimeValueException</code> : 시간 입력 부분에 정수가 오지 않으면 발생시킬 예외
  * <code>class TimeOutofBoundException</code> : HH가 24이상이거나, MM이 60이상일 때 발생시킬 예외
  * <code>class WrongTimeOrderException</code> : 시간 순서가 맞지 않을 때(ex. 0800~0400) 발생시킬 예외

