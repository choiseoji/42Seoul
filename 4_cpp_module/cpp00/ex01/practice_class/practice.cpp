#include <iostream>
using namespace std;

class Book     // Book class 선언
{
	private:
		int current_page;
		void set_percent();

	public:
		Book(const string &title, int total_page);  // 생성자
		string title_;
		int total_page_;
		// double percent_;
		void Move(int page);
		void Open();
		void Read();
		const Book& ThickerBook(const Book&);   // ThickerBook 함수의 원형
};

int main(void)
{
	Book web_book("HTML과 CSS", 350);
	Book html_book("HTML 래퍼런스", 200);

	cout << web_book.ThickerBook(html_book).title_;   // 더 두꺼운 책의 이름 출력
	return (0);
}

Book::Book(const string &title, int total_page)  // 멤버 변수 초기화
{
	title_ = title;
	total_page_ = total_page;
	// current_page_ = 0;
	// set_percent();
}

// this는 호출한 인스턴스를 가리킨다.
const Book& Book::ThickerBook(const Book& comp_book)
{
	if (comp_book.total_page_> this->total_page_)
		return (comp_book);
	else
		return *this;
}
