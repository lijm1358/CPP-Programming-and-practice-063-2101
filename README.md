# CPP-Programming-and-practice-063-2101
-------
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
## function.cpp
### main()에서 호출될 함수들 목록(LectureHandler를 인자로 받는 것은 실행 테스트 때문, 변경 가능)
* ### 함수 목록
  * <code>AddLecture(LectureHandler& lectHdl, professor& prof)</code> : 강의 추가
  * <code>ShowAllLecture(LectureHandler& lectHdl)</code> : 모든 강의 정보 출력
  * <code>AddGrade(LectureHandler& lectHdl, UserHandler& userHdl, professor& prof)</code> : 인자로 전달받은 professor클래스가 생성한 강의, 전체 강의 목록, 전체 사용자 목록 등의 정보를 이용해 학생들의 성적 등록.

