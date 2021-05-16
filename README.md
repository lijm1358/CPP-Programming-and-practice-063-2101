# CPP-Programming-and-practice-063-2101-TempProject
-------
* ### 멤버변수 목록
  * <code>Lecture* lectureList</code> : Lecture들을 저장할 수 있는 배열
  * <code>int lectureCount</code> : lectureList에 저장되어있는 lecture들의 수
  * <code>static int lectureCodeSequence</code> : lecture를 추가할 때 마다, 설정할 강의 코드. 1부터 시작하여 추가할 때 마다 1씩 늘어남.
* ### 멤버함수 목록
  * <code>void addLecture()</code> : lectureList에 강의 추가. 매개변수, 반환 없이 함수 내에서 모든 동작 처리
  * <code>void showAllLecture()</code> : lectureList에 있는 모든 강의들에 대한 정보 출력
  * <code>void changeLectureInfo()(Lecture&)</code> : Lecture 클래스 인스턴스를 받아서, 해당 lecture의 정보 변경. 변경할 정보 등의 선택은 함수 내에서 이루어짐.
  * <code>Lecture* findLecture(int) const</code> : 강의코드를 받아서, 해당 강의코드와 일차하는 lecture 클래스 반환. 일치하는 강의가 없으면 NULL반환.
  * <code>Lecture* findLecture(char*) const</code> : 강의명을 받아서, 해당 강의명과 일치하는 lecture 클래스 반환. 일치하는 강의가 없으면 NULL반환. 