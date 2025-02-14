#include <iostream>
#include <time.h>

using namespace std;

int main() {

	// 상수: 변하지 않는 수, 값을 한 번 지정하면 바꿀 수 없다
	// 상수는 선언과 동시에 값을 지정해두어야 한다.
	const int iAttack = 0x00000001;		//1(이진수)
	const int iArmor = 0x00000002;		//10
	const int iHP = 0x00000004;			//100
	const int iMP = 0x00000008;			//1000
	const int iCritical = 0x00000010;	//10000

	// 001 | 100 = 00101 | 10000 = 10101
	int iBuf = iAttack | iHP | iCritical;

	//연산자 축약형: 연산자를 줄여서 사용할 수 있다
	//아래를 풀어서 쓰면 iBuf = iBuf ^ iHP;
	//10101  ^ 00100 = 10001, HP가 사라짐
	iBuf ^= iHP;

	//10001 ^ 00100 = 10101, HP가 다시 생김
	iBuf ^= iHP;
	//XOR로 껐다 켰다 하는 스위치 기능을 만들어 낼 수 있다


	//각 비트들이 현재 켜져있는지 꺼져 있는지 확인 가능
	// 10101 & 00001 = 1 -> Attack이 있다(위 iBuf에 Attack 존재)
	cout << "Attack: " << (iBuf & iAttack) << endl;
	// 10101 & 00010 = 0 -> Armor가 없다(위 iBuf에 Attack 존재x)
	cout << "Armor: " << (iBuf & iArmor) << endl;
	cout << "HP: " << (iBuf & iHP) << endl;
	cout << "MP: " << (iBuf & iMP) << endl;
	cout << "Critical: " << (iBuf & iCritical) << endl;

	/*
	쉬프트 연산자: <<, >> 값 대 값을 연산하여 값으로 나오게 된다.
	이 연산자 또한 이진수 단위의 연산을 하게 된다.
	일반적인 연산보다 속도가 빠르다. 2의 n승 연산시 최적화 가능
	20 << 2 = 1010000(2) = 80(10) -> 20 * 2의 2승
	20 << 3 = 10100000(2) = 160(10) -> 20 * 2의 3승
	20 << 4 = 101000000(2) = 320(10) -> 20 * 2의 4승

	20 >> 2 = 101(2) = 5(10) ->20 * 1/(2의 2승) => 나눗셈
	20 >> 3 = 10(2) = 2(10) ->20 * 1/(2의 3승)
	
	*/

	int iHight = 187;
	int iLow = 13560;

	int iNumber = iHight;

	//iNumber에는 187이 들어가 있다. 이 값을 <- 이 방향으로 16비트 이동시키면
	//상위 16비트에 값이 들어가게 된다.
	iNumber <<= 16;

	//하위 16비트를 채운다.
	iNumber |= iLow;

	//High 값을 출력한다.
	cout << "High : " << (iNumber >> 16) << endl;
	cout << "Low : " << (iNumber & 0x0000ffff) << endl;

	//증감연산자 : ++, --
	iNumber = 10;

	//전치
	++iNumber;

	//후치
	iNumber++;

	cout << ++iNumber << endl;	//13
	cout << iNumber++ << endl;	//13, 출력 먼저 해놓고 증가시키기
	cout << iNumber << endl;	//14

	/*
	분기문에는 크게 2가지 종류가 있다. 
	if문: 조건을 체크해주는 기능.
	형태: if(조건식) {}(코드블럭)
	if문은 조건식이 true가 될 경우 코드블럭 내의 코드가 동작.
	false일 경우에는 동작하지 않음. 
	*/
	if (true) {
		cout << "if문 조건식이 true입니다." << endl;
	}

	//버프가 있는지 확인
	if ((iBuf & iAttack) != 0) {
		cout << "Attack 버프가 있습니다." << endl;
	}

	//if문 아래에 들어갈 코드가 1줄일 경우 {}(코드블럭)을 생략할 수 있다.
	if ((iBuf & iArmor) != 0)
		cout << "iArmor 버프가 있습니다." << endl;

	if ((iBuf & iHP) != 0) 
		cout << "HP 버프가 있습니다." << endl;
	
	if ((iBuf & iMP) != 0) 
		cout << "iMP 버프가 있습니다." << endl;
	
	if ((iBuf & iCritical) != 0) 
		cout << "iCritical 버프가 있습니다." << endl;

	/*
	else: if문과 반드시 같이 사용해야 한다.
	if문 조건이 false일 경우 else가 있다면 else 구문 안의 코드가 동작된다.
	
	else if : if문과 반드시 같이 사용해야 한다.
	if문 아래 와야 하고 else보다는 위에 있어야 한다.
	else if는 자신의 위에 있는 조건식이 false일 경우 다음 else if의 조건식을 체크한다.
	else if는 몇개든 사용이 가능하다.
	*/
	if (false)
		cout << "if문 조건이 true입니다." << endl;
	else
		cout << "if문 조건이 false입니다." << endl;

	cout << "숫자를 입력하세요" << endl;
	cin >> iNumber;

	if (10 <= iNumber && iNumber <= 20)
		cout << "10 ~ 20 사이의 숫자입니다." << endl;
	else if (21 <= iNumber && iNumber <= 30)
		cout << "21 ~ 30 사이의 숫자입니다." << endl;
	else if (31 <= iNumber && iNumber <= 40)
		cout << "31 ~ 40 사이의 숫자입니다." << endl;
	else
		cout << "그 외의 숫자입니다." << endl;

	//난수 발생
	srand((unsigned int)time(0));

	cout << rand() << endl;
	cout << rand() << endl;
	cout << rand() << endl;
	//0 ~ 99구하기. 어떤 수를 100으로 나누었을 때 나올 수 있는 수는 무조건 0~99임
	cout << (rand() % 100) << endl;  
	//100 ~ 200구하기
	cout << (rand() % 101 + 100) << endl;
	//0 ~ 99.99까지. 퍼센테이지 구하기. 소수점 두 자리까지 난수 생성, rand는 10000단위까지밖에 안 나옴->소수점 세 자리 이상 불가
	cout << (rand() % 10000 / 100.f) << endl;

	int iUpgrade = 0;
	cout << "Upgrade 기본 수치를 입력하세요: ";
	cin >> iUpgrade;

	//강화 확률을 구한다.
	float fPercent = rand() % 10000 / 100.f;

	//강화 확률: 업그레이드가 0 ~ 3 : 100% 성공 4 ~ 6 : 40% 7 ~ 9 : 10%
	//10 ~ 13 : 1% 14 ~ 15 : 0.01%
	cout << "Upgrade : " << iUpgrade << endl;
	cout << "Percent : " << fPercent << endl;

	if (iUpgrade <= 3)
		cout << "강화 성공" << endl;

	else if (4 <= iUpgrade && iUpgrade <= 6) {
		if (fPercent < 40.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}

	else if (4 <= iUpgrade && iUpgrade <= 9) {
		if (fPercent < 10.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}

	else if (10 <= iUpgrade && iUpgrade <= 13) {
		if (fPercent < 1.f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}

	else if (14 <= iUpgrade && iUpgrade <= 15) {
		if (fPercent < 0.01f)
			cout << "강화 성공" << endl;
		else
			cout << "강화 실패" << endl;
	}

	return 0;
}