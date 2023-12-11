[아직 모르는거]
- const 함수에 대해 더 알아보기
- static 변수 알아보기
- Account 초기화하는 부분을 잘 살펴보자

</br>
</br>


[고칠 거]
- 소멸자 호출 시  closed 문구가 나오도록 했는데 출력 순서가 다 반대임 -> 근데 이건 운영체제 마다 달라서!! 괜찮은 듯 (O)
- _totalNbWithdrawals, _totalNbDeposits 값 갱신이 안되고 있음 (O)
- 인덱스 처리가 안되고 있음 -> 갱신되기 전 _nbAccounts로 index 설정 해주면 된다 (O)
