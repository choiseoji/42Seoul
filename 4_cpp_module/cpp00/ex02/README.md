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


</br>
</br>


[물어볼 거]
- makeWithdrawal 함수의 반환형이 bool인데 amount - withdrawl이 양수일때 true, 0이거나 음수일때 false를 반환하는게 맞는지 (O)
- 위의 amount - withdrawl이 양수, 음수 인 것을 판별할 때 checkAmount 함수를 쓰는게 맞는지 (checkAmount 함수를 어쩔 때 사용하는지 잘 모르겠다)
- deposit이 0 일때는 nb_deposit을 0으로 해줬는데 이게 맞는지.. (내 맘대로 하면 될 듯)