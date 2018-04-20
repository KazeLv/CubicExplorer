#include"CubicExplorer.h"

CubicExplorer::CubicExplorer(char* cstr,HandState& hs):target(cstr),handState(hs){}

void CubicExplorer::OnR(vector<string>::iterator& iter) {
	RightTight();
	GetLeftReadyAndTight();
	macVec.push_back(Operation::R);
	handState.right.isReady = !handState.right.isReady;
	//if (*(iter + 1) == "U") {
	//	iter++;
	//	On_RR(iter);
	//	OnF(iter);
	//}
	//else if (*(iter + 1) == "U'") {
	//	iter++;
	//	On_RR(iter);
	//	On_F(iter);
	//}
	//else if (*(iter + 1) == "B") {
	//	iter++;
	//	OnRR(iter);
	//	OnF(iter);
	//}
	//else if (*(iter + 1) == "B'") {
	//	iter++;
	//	OnRR(iter);
	//	On_F(iter);
	//}
}

void CubicExplorer::On_R(vector<string>::iterator& iter) {
	RightTight();
	GetLeftReadyAndTight();
	macVec.push_back(Operation::_R);
	handState.right.isReady = !handState.right.isReady;
	/*if (*(iter + 1) == "U") {
		iter++;
		On_RR(iter);
		OnF(iter);
	}
	else if (*(iter + 1) == "U'") {
		iter++;
		On_RR(iter);
		On_F(iter);
	}
	else if (*(iter + 1) == "B") {
		iter++;
		OnRR(iter);
		OnF(iter);
	}
	else if (*(iter + 1) == "B'") {
		iter++;
		OnRR(iter);
		On_F(iter);
	}*/
}

void CubicExplorer::OnF(vector<string>::iterator& iter) {
	LeftTight();
	GetRightReadyAndTight();
	macVec.push_back(Operation::F);
	handState.left.isReady = !handState.left.isReady;
	/*if (*(iter + 1) == "U") {
		iter++;
		OnFF(iter);
		OnR(iter);
	}
	else if (*(iter + 1) == "U'") {
		iter++;
		OnFF(iter);
		On_R(iter);
	}
	else if (*(iter + 1) == "B") {
		iter++;
		On_FF(iter);
		OnR(iter);
	}
	else if (*(iter + 1) == "B'") {
		iter++;
		On_FF(iter);
		On_R(iter);
	}*/
}

void CubicExplorer::On_F(vector<string>::iterator& iter) {
	LeftTight();
	GetRightReadyAndTight();
	macVec.push_back(Operation::_F);
	handState.left.isReady = !handState.left.isReady;
	/*if (*(iter + 1) == "U") {
		iter++;
		OnFF(iter);
		OnR(iter);
	}
	else if (*(iter + 1) == "U'") {
		iter++;
		OnFF(iter);
		On_R(iter);
	}
	else if (*(iter + 1) == "B") {
		iter++;
		On_FF(iter);
		OnR(iter);
	}
	else if (*(iter + 1) == "B'") {
		iter++;
		On_FF(iter);
		On_R(iter);
	}
*/
}

void CubicExplorer::OnRR(vector<string>::iterator& iter) {
	RightTight();
	LeftLoose();
	LeftReady();
	macVec.push_back(Operation::R);
	handState.right.isReady = !handState.right.isReady;
	for (auto it = iter + 1; it != strNorVec.end(); it++) {
		if (*it == "U") *it = "B";
		else if (*it == "B") *it = "D";
		else if (*it == "D") *it = "F";
		else if (*it == "F") *it = "U";
		else if (*it == "U'") *it = "B'";
		else if (*it == "B'") *it = "D'";
		else if (*it == "D'") *it = "F'";
		else if (*it == "F'") *it = "U'";
		else if (*it == "U2") *it = "B2";
		else if (*it == "B2") *it = "D2";
		else if (*it == "D2") *it = "F2";
		else if (*it == "F2") *it = "U2";
	}
}

void CubicExplorer::On_RR(vector<string>::iterator& iter) {
	RightTight();
	LeftLoose();
	LeftReady();
	macVec.push_back(Operation::_R);
	handState.right.isReady = !handState.right.isReady;
	for (auto it = iter + 1; it != strNorVec.end(); it++) {
		if (*it == "U") *it = "F";
		else if (*it == "B") *it = "U";
		else if (*it == "D") *it = "B";
		else if (*it == "F") *it = "D";
		else if (*it == "U'") *it = "F'";
		else if (*it == "B'") *it = "U'";
		else if (*it == "D'") *it = "B'";
		else if (*it == "F'") *it = "D'";
		else if (*it == "U2") *it = "F2";
		else if (*it == "B2") *it = "U2";
		else if (*it == "D2") *it = "B2";
		else if (*it == "F2") *it = "D2";
	}
}

void CubicExplorer::OnFF(vector<string>::iterator& iter) {
	LeftTight();
	RightLoose();
	RightReady();
	macVec.push_back(Operation::F);
	handState.left.isReady = !handState.left.isReady;
	for (auto it = iter + 1; it != strNorVec.end(); it++) {
		if (*it == "U") *it = "R";
		else if (*it == "R") *it = "D";
		else if (*it == "D") *it = "L";
		else if (*it == "L") *it = "U";
		else if (*it == "U'") *it = "R'";
		else if (*it == "R'") *it = "D'";
		else if (*it == "D'") *it = "L'";
		else if (*it == "L'") *it = "U'";
		else if (*it == "U2") *it = "R2";
		else if (*it == "R2") *it = "D2";
		else if (*it == "D2") *it = "L2";
		else if (*it == "L2") *it = "U2";
	}
}

void CubicExplorer::On_FF(vector<string>::iterator& iter) {
	LeftTight();
	RightLoose();
	RightReady();
	macVec.push_back(Operation::_F);
	handState.left.isReady = !handState.left.isReady;
	for (auto it = iter + 1; it != strNorVec.end(); it++) {
		if (*it == "U") *it = "L";
		else if (*it == "R") *it = "U";
		else if (*it == "D") *it = "R";
		else if (*it == "L") *it = "D";
		else if (*it == "U'") *it = "L'";
		else if (*it == "R'") *it = "U'";
		else if (*it == "D'") *it = "R'";
		else if (*it == "L'") *it = "D'";
		else if (*it == "U2") *it = "L2";
		else if (*it == "R2") *it = "U2";
		else if (*it == "D2") *it = "R2";
		else if (*it == "L2") *it = "D2";
	}
}

void CubicExplorer::OnRR2(vector<string>::iterator& iter) {
	RightTight();
	LeftLoose();
	LeftReady();
	macVec.push_back(Operation::R2);
	for (auto it = iter + 1; it != strNorVec.end(); it++) {
		if (*it == "U") *it = "D";
		else if (*it == "B") *it = "F";
		else if (*it == "D") *it = "U";
		else if (*it == "F") *it = "B";
		else if (*it == "U'") *it = "D'";
		else if (*it == "B'") *it = "F'";
		else if (*it == "D'") *it = "U'";
		else if (*it == "F'") *it = "B'";
		else if (*it == "U2") *it = "D2";
		else if (*it == "B2") *it = "F2";
		else if (*it == "D2") *it = "U2";
		else if (*it == "F2") *it = "B2";
	}

}

void CubicExplorer::OnFF2(vector<string>::iterator& iter) {
	LeftTight();
	RightLoose();
	RightReady();
	macVec.push_back(Operation::F2);
	for (auto it = iter + 1; it != strNorVec.end(); it++) {
		if (*it == "U") *it = "D";
		else if (*it == "R") *it = "L";
		else if (*it == "D") *it = "U";
		else if (*it == "L") *it = "R";
		else if (*it == "U'") *it = "D'";
		else if (*it == "R'") *it = "L'";
		else if (*it == "D'") *it = "U'";
		else if (*it == "L'") *it = "R'";
		else if (*it == "U2") *it = "D2";
		else if (*it == "R2") *it = "L2";
		else if (*it == "D2") *it = "U2";
		else if (*it == "L2") *it = "R2";
	}
}

void CubicExplorer::OnR2(vector<string>::iterator& iter) {
	RightTight();
	GetLeftReadyAndTight();
	macVec.push_back(Operation::R2);
}

void CubicExplorer::OnF2(vector<string>::iterator& iter) {
	LeftTight();
	GetRightReadyAndTight();
	macVec.push_back(Operation::F2);
}

void CubicExplorer::LeftLoose() {
	if (handState.left.isTight) {
		macVec.push_back(Operation::LeftLoose);
		handState.left.isTight = false;
	}
}

void CubicExplorer::LeftTight() {
	if (!handState.left.isTight) {
		if ((!handState.right.isReady) && (!handState.left.isReady)) {
			macVec.push_back(Operation::F);
		}
		macVec.push_back(Operation::LeftTight);
		handState.left.isTight = true;
	}
}

void CubicExplorer::LeftReady() {
	if (!handState.left.isReady) {
		macVec.push_back(Operation::F);
		handState.left.isReady = true;
	}
}

void CubicExplorer::RightLoose() {
	if (handState.right.isTight) {
		macVec.push_back(Operation::RightLoose);
		handState.right.isTight = false;
	}
}

void CubicExplorer::RightTight() {
	if (!handState.right.isTight) {
		if ((!handState.right.isReady) && (!handState.left.isReady)) {
			macVec.push_back(Operation::R);
		}
		macVec.push_back(Operation::RightTight);
		handState.right.isTight = true;
	}
}

void CubicExplorer::RightReady() {
	if (!handState.right.isReady) {
		macVec.push_back(Operation::R);
		handState.right.isReady = true;
	}
}

void CubicExplorer::GetLeftReadyAndTight() {
	if (handState.left.isReady) {
		if (!handState.left.isTight) {
			macVec.push_back(Operation::LeftTight);
			handState.left.isTight = true;
		}
	}
	else {
		if (handState.left.isTight) {
			macVec.push_back(Operation::LeftLoose);
			macVec.push_back(Operation::F);
			macVec.push_back(Operation::LeftTight);
		}
		else {
			macVec.push_back(Operation::F);
			macVec.push_back(Operation::LeftTight);
			handState.left.isTight = true;
		}
		handState.left.isReady = true;
	}
}

void CubicExplorer::GetRightReadyAndTight() {
	if (handState.right.isReady) {
		if (!handState.right.isTight) {
			macVec.push_back(Operation::RightTight);
			handState.right.isTight = true;
		}
	}
	else {
		if (handState.right.isTight) {
			macVec.push_back(Operation::RightLoose);
			macVec.push_back(Operation::R);
			macVec.push_back(Operation::RightTight);
		}
		else {
			macVec.push_back(Operation::R);
			macVec.push_back(Operation::RightTight);
			handState.right.isTight = true;
		}
		handState.right.isReady = true;
	}
}

void CubicExplorer::GetShortestWay() {
	string::size_type lastSpace = 0;	//记录上一次遇到空格的位置
	//将原始字符串分割为多个表示单个操作的字符串并存放到strNorVec容器中
	string::size_type i = 0;
	for (; i < target.length(); i++) {
		if (target[i] == ' ') {
			string strTemp;
			for (string::size_type index = lastSpace; index < i; index++) {
				strTemp.push_back(target[index]);
			}
			strNorVec.push_back(strTemp);
			lastSpace = i + 1;
		}
	}/*
	strNorVec.push_back(string(target, lastSpace, i - 1));*/

	//显示分离结果，主要用于调试
	//for (auto it = strNorVec.cbegin(); it != strNorVec.cend(); it++) {
	//	cout << *it << " ";
	//}
	//cout << endl;

	//将分割得到的字符串操作序列转换为普通操作枚举类型存入norVec容器
	for (auto iter = strNorVec.begin(); iter != strNorVec.end(); iter++) {
		if (*iter == "R") OnR(iter);
		else if (*iter == "F") OnF(iter);
		else if (*iter == "R'") On_R(iter);
		else if (*iter == "F'") On_F(iter);
		else if (*iter == "R2") OnR2(iter);
		else if (*iter == "F2") OnF2(iter);
		else if (*iter == "B") {
			OnRR2(iter);
			OnF(iter);
		}
		else if (*iter == "L") {
			OnFF2(iter);
			OnR(iter);
		}
		else if (*iter == "U") {
			OnFF(iter);
			OnR(iter);
		}
		else if (*iter == "D") {
			OnRR(iter);
			OnF(iter);
		}
		else if (*iter == "B'") {
			OnRR2(iter);
			On_F(iter);
		}
		else if (*iter == "L'") {
			OnFF2(iter);
			On_R(iter);
		}
		else if (*iter == "U'") {
			OnFF(iter);
			On_R(iter);
		}
		else if (*iter == "D'") {
			OnRR(iter);
			OnF(iter);
		}
		else if (*iter == "B2") {
			OnRR2(iter);
			OnF2(iter);
		}
		else if (*iter == "L2") {
			OnFF2(iter);
			OnR2(iter);
		}
		else if (*iter == "U2") {
			OnFF(iter);
			OnR2(iter);
		}
		else if (*iter == "D2") {
			OnRR(iter);
			OnF2(iter);
		}
	}

	for (auto iter = macVec.begin(); iter != macVec.end(); iter++) {
		serialInterfaceStr += "#";
		switch (*iter) {
		case Operation::F:
			serialInterfaceStr += "1P7T200";
			break;
		case Operation::_F:
			serialInterfaceStr += "1P6T200";
			break;
		case Operation::F2:
			serialInterfaceStr += "1P8T200";
			break;
		case Operation::LeftLoose:
			serialInterfaceStr += "2P0T200";
			break;
		case Operation::LeftTight:
			serialInterfaceStr += "2P1T200";
			break;
		case Operation::R:
			serialInterfaceStr += "3P7T200";
			break;
		case Operation::_R:
			serialInterfaceStr += "3P6T200";
			break;
		case Operation::R2:
			serialInterfaceStr += "3P8T200";
			break;
		case Operation::RightLoose:
			serialInterfaceStr += "4P0T200";
			break;
		case Operation::RightTight:
			serialInterfaceStr += "4P1T200";
			break;
		}
		serialInterfaceStr += "\r\n";
	}
}

void CubicExplorer::ShowOperations() {
	int cnt = 0;
	for (auto iter = macVec.cbegin(); iter != macVec.cend(); iter++) {
		if (*iter != Operation::LeftLoose&&*iter != Operation::LeftTight&&*iter != Operation::RightLoose&&*iter != Operation::RightTight) {
			cnt++;
		}
		cout << *iter <<"   ";
	}
	cout << endl;
	cout << "Final operations' count: " << cnt << endl;
	cout << "All operations' count: " << macVec.size() << endl;
	cout << endl;
	cout << "SerialInterfaceStr: " << endl;
	cout << serialInterfaceStr << endl;
}


ostream& operator<<(ostream& os, const Operation& oper) {
	switch (oper) {
	case Operation::F:
		os << "F";
		break;
	case Operation::F2:
		os << "F2";
		break;
	case Operation::LeftLoose:
		os << "LeftLoose";
		break;
	case Operation::LeftTight:
		os << "LeftTight";
		break;
	case Operation::R:
		os << "R";
		break;
	case Operation::R2:
		os << "R2";
		break;
	case Operation::RightLoose:
		os << "RightLoose";
		break;
	case Operation::RightTight:
		os << "RightTight";
		break;
	case Operation::_F:
		os << "_F";
		break;
	case Operation::_R:
		os << "_R";
		break;
	}
	return os;
}