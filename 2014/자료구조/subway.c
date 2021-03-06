#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define max_s 20 // 문자열 역 이름
#define max_info_size 1000 // 환승정보

typedef struct Subtype
{
	int line;
	int sta_num;  //각각의 station의 번호
	int tline1;   //환승할수 있는 라인
	int tline2;   //환승할수 있는 라인
	char sta_info[max_info_size];
	char sta[max_s];
} Subtype;

typedef struct Sub_node
{
	Subtype data;
	struct Sub_node *llink;
	struct Sub_node *rlink;
} Sub_node;


void insert_node(Sub_node **phead, int line, int *i, int tline1, int tline2, char *sta, char *sta_info)
{
	Sub_node *new = (Sub_node *)malloc(sizeof(Sub_node));
	if(new == NULL)
	{
		fprintf(stderr,"메모리 할당 에러\n");
		exit(1);
	}
	new->data.line = line;
	new->data.tline1 = tline1;
	new->data.tline2 = tline2;
	new->data.sta_num = ++(*i);
	
	strcpy(new->data.sta, sta);
	strcpy(new->data.sta_info, sta_info);
	if(*phead == NULL)
	{
		*phead = new;
		new->llink = NULL;
		new->rlink = NULL;
	}
	else
	{
		(*phead)->rlink = new;
		new->llink = (*phead);
		new->rlink = NULL;
		(*phead) = (*phead)->rlink;
	}
}


Sub_node *made_line1(Sub_node *head)
{
	int i =0;
	head = NULL;
	
	insert_node(&head, 1, &i, 0, 0, "구로", "없음");
	insert_node(&head, 1, &i, 2, 0, "신도림", "없음");
	insert_node(&head, 1, &i, 0, 0, "영등포", "없음");
	insert_node(&head, 1, &i, 5, 0, "신길", "없음");
	insert_node(&head, 1, &i, 0, 0, "대방", "없음");
	insert_node(&head, 1, &i, 0, 0, "노량진", "없음");
	insert_node(&head, 1, &i, 0, 0, "용산", "없음");
	insert_node(&head, 1, &i, 0, 0, "남영", "없음");
	insert_node(&head, 1, &i, 4, 0, "서울", "10-4번 칸에서 내리면 빨리 환승할 수 있습니다.");
	insert_node(&head, 1, &i, 2, 0, "시청", "없음");
	insert_node(&head, 1, &i, 0, 0, "종각", "없음");
	insert_node(&head, 1, &i, 3, 5, "종로3가", "없음");
	insert_node(&head, 1, &i, 0, 0, "종로5가", "없음");
	insert_node(&head, 1, &i, 4, 0, "동대문", "없음");
	insert_node(&head, 1, &i, 0, 0, "동묘앞", "없음");
	insert_node(&head, 1, &i, 0, 0, "신설동", "없음");
	insert_node(&head, 1, &i, 0, 0, "제기동", "없음");
	insert_node(&head, 1, &i, 0, 0, "청량리", "없음");
	insert_node(&head, 1, &i, 0, 0, "회기", "없음");
	insert_node(&head, 1, &i, 0, 0, "외대", "없음");
	insert_node(&head, 1, &i, 0, 0, "신이문", "없음");
	insert_node(&head, 1, &i, 0, 0, "석계", "없음");
	insert_node(&head, 1, &i, 0, 0, "성북", "없음");
	insert_node(&head, 1, &i, 0, 0, "월계", "없음");
	insert_node(&head, 1, &i, 0, 0, "녹천", "없음");
	insert_node(&head, 1, &i, 4, 0, "창동", "없음");
	insert_node(&head, 1, &i, 0, 0, "방학", "없음");
	insert_node(&head, 1, &i, 0, 0, "도봉", "없음");

// 28 station 입력
	return head;
}

Sub_node *made_line2(Sub_node *head)
{
	int i=0;
	head = NULL;

	insert_node(&head, 2, &i, 0, 0, "구로공단", "없음");
	insert_node(&head, 2, &i, 0, 0, "대림", "없음");
	insert_node(&head, 2, &i, 1, 0, "신도림", "없음");
	insert_node(&head, 2, &i, 0, 0, "문래", "없음");
	insert_node(&head, 2, &i, 5, 0, "영등포구청", "없음");
	insert_node(&head, 2, &i, 0, 0, "당산", "없음");
	insert_node(&head, 2, &i, 0, 0, "합정", "없음");
	insert_node(&head, 2, &i, 0, 0, "홍대입구", "없음");
	insert_node(&head, 2, &i, 0, 0, "신촌", "없음");
	insert_node(&head, 2, &i, 0, 0, "이대", "없음");
	insert_node(&head, 2, &i, 0, 0, "아현", "없음");
	insert_node(&head, 2, &i, 5, 0, "충정로", "없음");
	insert_node(&head, 2, &i, 1, 0, "시청", "없음");
	insert_node(&head, 2, &i, 0, 0, "을지로입구", "없음");
	insert_node(&head, 2, &i, 3, 0, "을지로3가", "없음");
	insert_node(&head, 2, &i, 5, 0, "을지로4가", "없음");
	insert_node(&head, 2, &i, 4, 5, "동대문운동장", "없음");
	insert_node(&head, 2, &i, 0, 0, "신당", "없음");
	insert_node(&head, 2, &i, 0, 0, "상왕십리", "없음");
	insert_node(&head, 2, &i, 5, 0, "왕십리", "없음");
	insert_node(&head, 2, &i, 0, 0, "한양대", "없음");
	insert_node(&head, 2, &i, 0, 0, "뚝섬", "없음");
	insert_node(&head, 2, &i, 0, 0, "성수", "없음");
	insert_node(&head, 2, &i, 0, 0, "건대입구", "없음");
	insert_node(&head, 2, &i, 0, 0, "구의", "없음");
	insert_node(&head, 2, &i, 0, 0, "강변", "없음");
	insert_node(&head, 2, &i, 0, 0, "성내", "없음");
	insert_node(&head, 2, &i, 0, 0, "잠실", "없음");
	insert_node(&head, 2, &i, 0, 0, "신천", "없음");
	insert_node(&head, 2, &i, 0, 0, "종합운동장", "없음");
	insert_node(&head, 2, &i, 0, 0, "삼성", "없음");
	insert_node(&head, 2, &i, 0, 0, "선릉", "없음");
	insert_node(&head, 2, &i, 0, 0, "역삼", "없음");
	insert_node(&head, 2, &i, 0, 0, "강남", "없음");
	insert_node(&head, 2, &i, 3, 0, "교대", "없음");
	insert_node(&head, 2, &i, 0, 0, "서초", "없음");
	insert_node(&head, 2, &i, 0, 0, "방배", "없음");
	insert_node(&head, 2, &i, 4, 0, "사당", "없음");
	insert_node(&head, 2, &i, 0, 0, "낙성대", "없음");
	insert_node(&head, 2, &i, 0, 0, "서울대입구", "없음");
// 40 station 입력
	return head;
}

Sub_node *made_line3(Sub_node *head)
{
	int i=0;
	head = NULL;

	insert_node(&head, 3, &i, 0, 0, "홍제", "없음");
	insert_node(&head, 3, &i, 0, 0, "무악재", "없음");
	insert_node(&head, 3, &i, 0, 0, "독립문", "없음");
	insert_node(&head, 3, &i, 0, 0, "경복궁", "없음");
	insert_node(&head, 3, &i, 0, 0, "안국", "없음");
	insert_node(&head, 3, &i, 1, 5, "종로3가", "없음");
	insert_node(&head, 3, &i, 2, 0, "을지로3가", "없음");
	insert_node(&head, 3, &i, 4, 0, "충무로", "없음");
	insert_node(&head, 3, &i, 0, 0, "동대입구", "없음");
	insert_node(&head, 3, &i, 0, 0, "약수", "없음");
	insert_node(&head, 3, &i, 0, 0, "금호", "없음");
	insert_node(&head, 3, &i, 0, 0, "옥수", "없음");
	insert_node(&head, 3, &i, 0, 0, "압구정", "없음");
	insert_node(&head, 3, &i, 0, 0, "신사", "없음");
	insert_node(&head, 3, &i, 0, 0, "잠원", "없음");
	insert_node(&head, 3, &i, 0, 0, "고속터미널", "없음");
	insert_node(&head, 3, &i, 2, 0, "교대", "없음");
	insert_node(&head, 3, &i, 0, 0, "남부터미널", "없음");
	insert_node(&head, 3, &i, 0, 0, "양재", "없음");
// 19 station 입력
	return head;
}

Sub_node *made_line4(Sub_node *head)
{
	int i=0;
	head = NULL;

	insert_node(&head, 4, &i, 0, 0, "당고개", "없음");
	insert_node(&head, 4, &i, 0, 0, "상계", "없음");
	insert_node(&head, 4, &i, 0, 0, "노원", "없음");
	insert_node(&head, 4, &i, 1, 0, "창동", "없음");
	insert_node(&head, 4, &i, 0, 0, "쌍문", "없음");
	insert_node(&head, 4, &i, 0, 0, "수유", "없음");
	insert_node(&head, 4, &i, 0, 0, "미아", "없음");
	insert_node(&head, 4, &i, 0, 0, "미아삼거리", "없음");
	insert_node(&head, 4, &i, 0, 0, "길음", "없음");
	insert_node(&head, 4, &i, 0, 0, "성신여대입구", "없음");
	insert_node(&head, 4, &i, 0, 0, "한성대입구", "없음");
	insert_node(&head, 4, &i, 0, 0, "혜화", "없음");
	insert_node(&head, 4, &i, 1, 0, "동대문", "없음");
	insert_node(&head, 4, &i, 2, 5, "동대문운동장", "없음");
	insert_node(&head, 4, &i, 3, 0, "충무로", "없음");
	insert_node(&head, 4, &i, 0, 0, "명동", "없음");
	insert_node(&head, 4, &i, 0, 0, "회현", "없음");
	insert_node(&head, 4, &i, 1, 0, "서울", "10-4번 칸에서 내리면 빨리 환승할 수 있습니다.");
	insert_node(&head, 4, &i, 0, 0, "숙대입구", "없음");
	insert_node(&head, 4, &i, 0, 0, "삼각지", "없음");
	insert_node(&head, 4, &i, 0, 0, "신용산", "없음");
	insert_node(&head, 4, &i, 0, 0, "이촌", "없음");
	insert_node(&head, 4, &i, 0, 0, "동작", "없음");
	insert_node(&head, 4, &i, 0, 0, "이수", "없음");
	insert_node(&head, 4, &i, 2, 0, "사당", "없음");
	insert_node(&head, 4, &i, 0, 0, "남태령", "없음");
	insert_node(&head, 4, &i, 0, 0, "선바위", "없음");
	insert_node(&head, 4, &i, 0, 0, "경마공원", "없음");
	insert_node(&head, 4, &i, 0, 0, "대공원", "없음");
// 29 station 입력
	return head;
}

Sub_node *made_line5(Sub_node *head)
{
	int i=0;
	head = NULL;

	insert_node(&head, 5, &i, 0, 0, "목동", "없음");
	insert_node(&head, 5, &i, 0, 0, "오목교", "없음");
	insert_node(&head, 5, &i, 0, 0, "양평", "없음");
	insert_node(&head, 5, &i, 2, 0, "영등포구청", "없음");
	insert_node(&head, 5, &i, 0, 0, "영등포시장", "없음");
	insert_node(&head, 5, &i, 1, 0, "신길", "없음");
	insert_node(&head, 5, &i, 0, 0, "여의도", "없음");
	insert_node(&head, 5, &i, 0, 0, "여의나루", "없음");
	insert_node(&head, 5, &i, 0, 0, "마포", "없음");
	insert_node(&head, 5, &i, 0, 0, "공덕", "없음");
	insert_node(&head, 5, &i, 0, 0, "애오개", "없음");
	insert_node(&head, 5, &i, 2, 0, "충정로", "없음");
	insert_node(&head, 5, &i, 0, 0, "서대문", "없음");
	insert_node(&head, 5, &i, 0, 0, "광화문", "없음");
	insert_node(&head, 5, &i, 1, 3, "종로3가", "없음");
	insert_node(&head, 5, &i, 2, 0, "을지로4가", "없음");
	insert_node(&head, 5, &i, 2, 4, "동대문운동장", "없음");
	insert_node(&head, 5, &i, 0, 0, "청구", "없음");
	insert_node(&head, 5, &i, 0, 0, "신금호", "없음");
	insert_node(&head, 5, &i, 0, 0, "행당", "없음");
	insert_node(&head, 5, &i, 2, 0, "왕십리", "없음");
	insert_node(&head, 5, &i, 0, 0, "마장", "없음");
	insert_node(&head, 5, &i, 0, 0, "답십리", "없음");
	insert_node(&head, 5, &i, 0, 0, "장한평", "없음");
// 24 station 입력
	return head;
}

Sub_node *starting_find(Sub_node *head, Sub_node *head1, Sub_node *head2, Sub_node *head3, Sub_node *head4, Sub_node *head5, Sub_node s)
{
	for(head1; head1 != NULL; head1 = head1->llink)
	{
		if(!(strcmp(head1->data.sta, s.data.sta)))
		{
			head = head1;
			return head;
		}
	}
	for(head2; head2 != NULL; head2 = head2->llink)
	{
		if(!(strcmp(head2->data.sta, s.data.sta)))
		{
			head = head2;
			return head;
		}
	}
	for(head3; head3 != NULL; head3 = head3->llink)
	{
		if(!(strcmp(head3->data.sta, s.data.sta)))
		{
			head = head3;
			return head;
		}
	}
	for(head4; head4 != NULL; head4 = head4->llink)
	{
		if(!(strcmp(head4->data.sta, s.data.sta)))
		{
			head = head4;
			return head;
		}
	}
	for(head5; head5 != NULL; head5 = head5->llink)
	{
		if(!(strcmp(head5->data.sta, s.data.sta)))
		{
			head = head5;
			return head;
		}
	}
	return NULL;
}

void display(Sub_node *head, Sub_node *end) 
{
	Sub_node *p, *q;
	p = head;
	q = end;

	printf("Line %d : %s (%s) \n", p->data.line, p->data.sta, p->data.sta_info);
	do {
		if (p->data.sta_num > q->data.sta_num)	{
			p = p->llink;
		} else {
			p = p->rlink;
		}
		printf("Line %d : %s (%s) \n", p->data.line, p->data.sta, p->data.sta_info);
	} while (p->data.sta != q->data.sta);
	
	printf("\n");
}

void subway_path_find(Sub_node *head, Sub_node *end)
{
	Sub_node *tmp1, *tail1;
	
	tmp1 = head;
	tail1 = end;

	if(tmp1->data.line == tail1->data.line)
	{	//출발역과 도착역이 같은 호선일 경우. 즉, 갈아타지 않는 경우
		display(tmp1, tail1);
	}
}



// 이중 연결 리스트 테스트 프로그램
void main()
{
	Sub_node s, e;
	Sub_node *head, *head1, *head2, *head3, *head4, *head5, *end;

	head = head1 = head2 = head3 = head4 = head5 = NULL;
	end = NULL;

	head1 = made_line1(head1);
	head2 = made_line2(head2);
	head3 = made_line3(head3);
	head4 = made_line4(head4);
	head5 = made_line5(head5);
	
	printf("\n\n 출발역을 입력하세요.('역'자는 제외) :  ");
	gets(s.data.sta);
	printf("\n");

	printf(" 도착역을 입력하세요.('역'자는 제외) :  ");
	gets(e.data.sta);

	head = starting_find(head, head1, head2, head3, head4, head5, s);
	end = starting_find(head, head1, head2, head3, head4, head5, e);

	while(head == NULL || end == NULL || head->data.sta == end->data.sta)
	{
		printf("\n 역 이름을 잘못 입력하였습니다.\n 다시 입력하세요. \n\n");
		printf(" 출발역을 입력하세요.('역'자는 제외) :  ");
		gets(s.data.sta);
		printf("\n");

		printf(" 도착역을 입력하세요.('역'자는 제외) :  ");
		gets(e.data.sta);
		
		head = starting_find(head, head1, head2, head3, head4, head5, s);
		end = starting_find(head, head1, head2, head3, head4, head5, e);
	}
	printf("\n\n");
	subway_path_find(head, end);
	printf("\n\n");
	getch();
	return;

}
