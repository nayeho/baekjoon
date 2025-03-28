#include <stdio.h>

int main(void)
{
    int N;
    scanf("%d", &N);
    
    if(N == 1)
    {
        printf("666");
        return 0;
    }
    // while문을 쭉 돌면서 N과 666의 횟수가 같아지면 break
    int i = 667; // 667부터 666이 연속되어 있는지 확인해보자
    int temp; // 안쪽에서 i를 수정하면 안되니 원본은 두고 복사본으로 체크하자
    int check = 0; // 666이 보이면 1로 수정 후 횟수 증가
    int count = 1; // 667부터 출발할 예정 -> 666이 이미 count 1개 늘려놓음
    while(1)
    {
        temp = i;
        check = 0;
        
        while(temp > 0) // 물론 C언어는 양수면 true긴 하다
        {
            if(temp % 1000 == 666) // 끝 세자리가 666이면
            {
                check = 1; // 666을 찾았다!
            }
            temp /= 10; // 끝자리 하나씩 지워가며 666 찾기
        }
        if(check == 1)
        {
            count++;
            if(count == N) break;
        }
        i++; // 다음 i를 확인하자
    }
    printf("%d", i);
    
    return 0;
}