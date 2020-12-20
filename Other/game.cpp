#pragma G++ optimize (2)
#include<cstdio>
#include<iostream>
#include<time.h>
#include<windows.h>
using namespace std;
struct player
{
    int Attack,Defence,HP,MP,MaxHP,MaxMP,Money;
    int SmallHP,MiddleHP,LargeHP,SmallMP,MiddleMP,LargeMP;
    int SmallAttack,MiddleAttack,LargeAttack,SuperAttack;
    int SKill1Level,SKill2Level,SKill3Level,Level,Experience;
    string UserName;
}player1;
bool life=1,ForestOpen,EatingGet,WorkOpen,Special;
int LevelMost=10,Mission1Get;
string MonsterName[20]={" ","小狮子","中狮子","大狮子","神圣狮子","神圣狮子王","小石怪","中石怪","大石怪","神圣石怪","神圣石怪王","混沌魔王"};
int MonsterAttack[20]={0,2,5,10,20,50,5,10,20,50,100,500};
int MonsterDefence[20]={0,0,3,5,10,20,3,5,10,20,50,300};
int MonsterHP[20]={0,10,20,50,100,500,20,50,100,500,1000,5000};
string Question[10]={"66+51=","51+49=","25+96=","56+52=","21+274="};
string Answer[10]={"117","100","121","108","295"};
int LevelUp[50]={0,10,20,50,200,500,3000,9000,13000,19000,30000,50000,60000,70000,90000,100000,120000,140000,150000,170000,200000,220000,222222,233333,240000,250000,270000,280000,300000,350000,400000};
string PassWord="地表最弱韶身";
void Slowsay(string a)
{
    int l=a.size();
    for(int i=0;i<l;i++)
    {
        cout<<a[i];
        Sleep(30);
    }
    printf("\n");
}
void Clear()
{
    Sleep(1500);
    system("cls");
}
void Start()
{
    Slowsay("输入A跳过剧情，否则输入任意字符");
    char c;
    cin>>c;
    if(c!='A')
    {
        Slowsay("......");
        Slowsay("......");
        Slowsay("......");
        system("cls");
        Slowsay("少年：这......这是哪里？");
        Sleep(1500);
        Slowsay("少年：为什么我手里握着一把剑，还穿着奇怪的铠甲？");
        Slowsay("来自天边的奇怪声音：少年，这是天赐圣剑和天赐圣铠，你是被上天选中的天选之子！");
        Slowsay("来自天边的奇怪声音：你的目标是解救被混沌魔王抢走的公主");
        Slowsay("少年：这不就是小木剑和布衣吗？");
        Sleep(1500);
        Slowsay("来自天边的奇怪声音：呃，其实你说对了，这就是小木剑和布衣，但它们是有等级的，到最高等级就变成了天赐圣剑和天赐圣铠了");
        Clear();
        Slowsay("来自天边的奇怪声音：它们一共有10级，下面介绍一下：");
        Slowsay("来自天边的奇怪声音：0级：小木剑和布衣");
        Slowsay("来自天边的奇怪声音：1级：匕首和斗篷");
        Slowsay("来自天边的奇怪声音：2级：短剑和轻铠");
        Slowsay("来自天边的奇怪声音：3级：铜剑和短铠");
        Slowsay("来自天边的奇怪声音：4级：铁剑和铁铠");
        Slowsay("来自天边的奇怪声音：5级：长剑和长铠");
        Slowsay("来自天边的奇怪声音：6级：重剑和重铠");
        Slowsay("来自天边的奇怪声音：7级：巨剑和巨铠");
        Slowsay("来自天边的奇怪声音：8级：剑王和铠王");
        Slowsay("来自天边的奇怪声音：9级：剑圣和铠圣");
        Slowsay("来自天边的奇怪声音：10级：天赐圣剑和天赐圣铠");
        Clear();
        Slowsay("来自天边的奇怪声音：接下来是操作方式");
        Slowsay("来自天边的奇怪声音：根据提示输入数字，千万不要输入不在范围内的数，否则可能会崩溃！");
        Slowsay("来自天边的奇怪声音：我会在旁边加括号的，括号里的是说明");
        Clear();
    }
    Slowsay("来自天边的奇怪声音：最后，告诉我你的名字是：");
    cin>>player1.UserName;
    if(player1.UserName=="kkksc03")
    {
        Slowsay("你一定不是kkksc03，所以朋友再见！");
        player1.HP=-666666; 
    }
    if(player1.UserName=="地表最弱韶身")
    {
        Slowsay("觉醒吧，沉睡多年的战神！");
        Slowsay("神圣觉醒！！！！！！！！！！！！！！！！！！！！");
        player1.HP=player1.MaxHP=player1.MaxMP=player1.MP=1000;
        player1.Attack=player1.Defence=300; 
    }
    Clear();
}
void Read()
{
    freopen("LMSN.text","r",stdin);
    cin>>player1.UserName;
    cin>>player1.Attack>>player1.Defence;
    cin>>player1.HP>>player1.MaxHP>>player1.MP>>player1.MaxMP;
    cin>>player1.Level>>player1.Experience;
    cin>>player1.SKill1Level>>player1.SKill2Level>>player1.SKill3Level;
    cin>>player1.SmallHP>>player1.MiddleHP>>player1.LargeHP;
    cin>>player1.SmallMP>>player1.MiddleMP>>player1.LargeMP;
    cin>>player1.SmallAttack>>player1.MiddleAttack>>player1.LargeAttack>>player1.SuperAttack;
    cin>>player1.Money;
    cin>>Mission1Get;
    cin>>ForestOpen;
    cin>>EatingGet;
    cin>>Special;
    cin>>LevelMost;
    fclose(stdin);
    freopen("CON","r",stdin);
}
void Save()
{
    freopen("LMSN.text","w",stdout);
    cout<<player1.UserName<<endl;
    cout<<player1.Attack<<endl;
    cout<<player1.Defence<<endl;
    cout<<player1.HP<<endl;
    cout<<player1.MaxHP<<endl;
    cout<<player1.MP<<endl;
    cout<<player1.MaxMP<<endl;
    cout<<player1.Level<<endl;
    cout<<player1.Experience<<endl;
    cout<<player1.SKill1Level<<endl;
    cout<<player1.SKill2Level<<endl;
    cout<<player1.SKill3Level<<endl;
    cout<<player1.SmallHP<<endl;
    cout<<player1.MiddleHP<<endl;
    cout<<player1.LargeHP<<endl;
    cout<<player1.SmallMP<<endl;
    cout<<player1.MiddleMP<<endl;
    cout<<player1.LargeMP<<endl;
    cout<<player1.SmallAttack<<endl;
    cout<<player1.MiddleAttack<<endl;
    cout<<player1.LargeAttack<<endl;
    cout<<player1.SuperAttack<<endl;
    cout<<player1.Money<<endl;
    cout<<Mission1Get<<endl;
    cout<<ForestOpen<<endl;
    cout<<EatingGet<<endl;
    cout<<Special<<endl;
    cout<<LevelMost<<endl;
    fclose(stdout);
}
void say(string a)
{
    int l=a.size();
    for(int i=0;i<l;i++)
    {
        cout<<a[i];
        Sleep(15);
    }
}
bool CanUse(int i)
{
    if(i==1&&player1.SmallHP)return 1;
    if(i==2&&player1.MiddleHP)return 1;
    if(i==3&&player1.LargeHP)return 1;
    if(i==4&&player1.SmallMP)return 1;
    if(i==5&&player1.MiddleMP)return 1;
    if(i==6&&player1.LargeMP)return 1;
    if(i==7&&player1.SmallAttack)return 1;
    if(i==8&&player1.MiddleAttack)return 1;
    if(i==9&&player1.LargeAttack)return 1;
    if(i==10&&player1.SuperAttack)return 1;
    return 0;
}
void Use(int i)
{
    if(i==1)
    {
        say("成功使用小血瓶，血量增加10点");
        printf("\n");
        player1.HP=min(player1.HP+10,player1.MaxHP);
        player1.SmallHP--;
    }
    if(i==2)
    {
        say("成功使用中血瓶，血量增加20点");
        printf("\n");
        player1.HP=min(player1.HP+20,player1.MaxHP);
        player1.MiddleHP--;
    }
    if(i==3)
    {
        say("成功使用大血瓶，血量增加50点");
        printf("\n");
        player1.HP=min(player1.HP+50,player1.MaxHP);
        player1.LargeHP--;
    }
    if(i==4)
    {
        say("成功使用小魔瓶，魔法值增加10点");
        printf("\n");
        player1.MP=min(player1.MP+10,player1.MaxMP);
        player1.SmallMP--;
    }
    if(i==5)
    {
        say("成功使用中魔瓶，魔法值增加20点");
        printf("\n");
        player1.MP=min(player1.MP+20,player1.MaxMP);
        player1.MiddleMP--;
    }
    if(i==6)
    {
        say("成功使用大魔瓶，魔法值增加50点");
        printf("\n");
        player1.MP=min(player1.MP+50,player1.MaxMP);
        player1.LargeMP--;
    }
}
bool LastMonster()
{
    Clear();
    int HP=10000;
    int Attack=1000;
    int Defence=500;
    while(HP>0&&player1.HP>0)
    {
        Clear();
        Slowsay("请输入你想执行的操作：");
        Slowsay("1：攻击    2：使用技能    3：使用道具");
        int x,End=1;
        cin>>x;
        if(x<0||x>3)continue;
        if(x==1)
        {
            if(player1.Attack<Defence)
            {
                say("攻击小于对手防御，建议逃跑或使用道具");
                printf("\n");
            }
            else 
            {
                HP-=player1.Attack-Defence;
                say("对敌人造成");printf("%d",player1.Attack-Defence);say("点伤害");
            }
        }
        if(x==2)
        {
            say("请输入想要使用的技能编号:(1为火球术,2为雷暴术,3为治疗术)");
            printf("\n");
            int y;
            cin>>y;
            if(y==1&&!player1.SKill1Level)
            {
                say("火球术尚未学习！");
                printf("\n");
                End=0;
            }
            if(y==2&&!player1.SKill2Level)
            {
                say("雷暴术尚未学习！");
                printf("\n");
                End=0;
            }
            if(y==3&&!player1.SKill3Level)
            {
                say("治疗术尚未学习！");
                printf("\n");
                End=0;
            }
            if(y==1&&player1.SKill1Level)
            {
                if(player1.MP<3)
                {
                    say("魔法值不足，使用失败");
                    printf("\n");
                    End=0;
                }
                else
                {
                    say("使用火球术，对敌人造成");printf("%d",5*player1.SKill1Level);say("点伤害");
                    printf("\n");
                    say("消耗3点魔法值");
                    printf("\n");
                    HP-=5*player1.SKill1Level;
                    player1.MP-=3;
                }
            }
            if(y==2&&player1.SKill2Level)
            {
                if(player1.MP<5)
                {
                    say("魔法值不足，使用失败");
                    printf("\n");
                    End=0;
                }
                else
                {
                    say("使用雷暴术，对敌人造成");printf("%d",10*player1.SKill2Level);say("点伤害");
                    printf("\n");
                    say("消耗5点魔法值");
                    printf("\n");
                    HP-=10*player1.SKill2Level;
                    player1.MP-=5;
                }
            }
            if(y==3&&player1.SKill3Level)
            {
                if(player1.MP<10)
                {
                    say("魔法值不足，使用失败");
                    printf("\n");
                    End=0;
                }
                else
                {
                    say("使用治疗术，回复");printf("%d",15*player1.SKill3Level);say("点血量");
                    printf("\n");
                    say("消耗10点魔法值");
                    printf("\n");
                    player1.HP=min(player1.MaxHP,player1.HP+15*player1.SKill3Level);
                    player1.MP-=10;
                }
            }
        }
        if(x==3)
        {
            say("请输入想要使用的道具编号，想查询道具的编号请输入-1");
            printf("\n");
            int y;
            cin>>y;
            if(y==-1)
            {
                say("1：小血瓶");
                printf("\n");
                say("2：中血瓶");
                printf("\n");
                say("3：大血瓶");
                printf("\n");
                say("4：小魔瓶");
                printf("\n");
                say("5：中魔瓶");
                printf("\n");
                say("6：大魔瓶");
                printf("\n");
                say("7：小炸弹");
                printf("\n");
                say("8：中炸弹");
                printf("\n");
                say("9：大炸弹");
                printf("\n");
                say("10：原子弹");
                printf("\n");
                End=0;
            }
            else if(CanUse(y)&&y<=6)Use(y);
                else if(CanUse(y)&&y>6)
                    {
                        if(y==7)
                        {
                            Slowsay("成功使用小炸弹，对敌人造成50点伤害");
                            HP-=50;
                            player1.SmallAttack--;
                        }
                        if(y==8)
                        {
                            Slowsay("成功使用中炸弹，对敌人造成100点伤害");
                            HP-=100;
                            player1.MiddleAttack--;
                        }
                        if(y==9)
                        {
                            Slowsay("成功使用大炸弹，对敌人造成200点伤害");
                            HP-=200;
                            player1.LargeAttack--;
                        }
                        if(y==10)
                        {
                            Slowsay("成功使用原子弹，对敌人造成500点伤害");
                            HP-=500;
                            player1.SuperAttack--;
                        }
                    }
                    else
                    {
                        say("道具不足，无法使用");
                        printf("\n");
                        End=0;
                    }
        }
        if(End)
        {
            player1.HP-=Attack-player1.Defence;
            say("灭世魔王对你造成了");printf("%d",Attack-player1.Defence);say("点伤害");
            printf("\n");
        }
    }
    if(player1.HP<=0)return 0;
    else return 1;
}
void Story2()
{
    Slowsay("少年又一次战胜了魔王，解救了公主");
    Slowsay("但是，这一次真的是大结局吗？");
    Slowsay("灭世魔王死后，从天而降，出现了两个人，他们浑身散发着耀眼的光芒");
    Slowsay("少年向他们跑去，他们就落了下来");
    Slowsay("他们一看就非常的厉害，少年于是问道：“您二位是从何而来？”");
    Slowsay("二人相视一笑，说：“我们这里有两首诗，你能看破玄机，我们就告诉你”");
    Slowsay("第一首：孔丘圣人于我后，");
    Slowsay("        雀雀飞升脱凡尘。");
    Slowsay("        明亮光芒照万物，");
    Slowsay("        王临天下第一人。");
    Slowsay("第二首：接凡渡尘非常人，");
    Slowsay("        引得世人入轮回。");
    Slowsay("        道行天下任我游，");
    Slowsay("        人间沧桑皆看破。");
    Slowsay("少年仔细想了一想，说：你们不就是《封神演义》里的孔雀明王和接引道人吗？");
    Slowsay("二人说：“不错，少年你很有天资，希望你以后能继续在惩恶扬善的道路上走下去，永不结束！！！”");
    Slowsay("少年说：“谢谢二位！我以后会继续努力的！”");
    Slowsay("剧情暂时告一段落，以后也不怎么会再更剧情了");
    Slowsay("敬请期待天选之子v1.3");
}
void TheEnd()
{
    LevelMost+=10; 
    Clear();
    Slowsay("我们的天选之子成功打败了混沌魔王，解救了公主");
    Slowsay("然而，公主却告诉他在混沌魔王之上，还有更厉害的魔王在等着他");
    Slowsay("但是，他无所畏惧，能够去打败更为强大的魔王！");
    Slowsay("就在这时，一个怪物出现了，它身上居然也穿着天赐圣剑和天赐圣铠！");
    Slowsay("少年为此所震惊，怪物却告诉他，他就是过去的它，它就是未来的他！");
    Slowsay("少年不相信，与怪物打了起来，但怪物实在太厉害，少年打不过它，少年落荒而逃");
    Slowsay("怪物又俘虏了公主，少年即将颓废，但是眼前忽然出现一个人！");
    Slowsay("他对少年说：“少年，你还记得我吗？”");
    Slowsay("少年仔细一想，说：“你是那个奇怪的声音！”");
    Slowsay("他说：“没错，就是我，其实世上的天选之子一共有过三个”");
    Slowsay("少年说：“怎么会有三个天选之子？！”");
    Slowsay("他说：“第一个是我，第二个是刚刚那个怪物，第三个是你”");
    Slowsay("他说：“其实，你所掌握的力量只是皮毛，看好了！”");
    Slowsay("突然，他的身上长出了一双无比华丽的翅膀");
    Slowsay("少年被此所惊到，他说：“天选之子的力量是无比强大的，但是怎么运用就看你了”");
    Slowsay("他说：“天选之子的力量既可以创造世界，也可以毁灭世界”");
    Slowsay("他说：“你的力量也有这么强大，不信你试试”");
    Slowsay("少年心中想着翅膀，身上便长出了翅膀！");
    Slowsay("他说：“你想什么，你就会拥有什么”");
    Slowsay("他说：“你可别想歪了啊！”");
    Slowsay("他说：“你可以获取所有你能想到的装备、东西、能力”");
    Slowsay("他说：“但是，为了防止你想歪，我只能送你一样能力”");
    Slowsay("他说：“那就是，无限正义，不要问我它有什么用，其实我也不知道”");
    Slowsay("他说：“好了，少年，去战胜怪物吧”");
    Slowsay("他说：“对了，怪物的名字叫做灭世魔王”");
    player1.Attack*=2;
    player1.Defence*=2;
    player1.HP=player1.MaxHP*=2;
    player1.MP=player1.MaxMP*=2;
    if(LastMonster())Story2();
    Slowsay("未完待续......");
}
void Die()
{
    Clear();
    Slowsay("不...我还不能死...我还没有打败混沌魔王...");
    Slowsay("我要复活！！！！！！！！");
    Save();
    Sleep(50000);
    Slowsay("复活成功");
    player1.HP=player1.MaxHP; 
}
int Fight(int i)
{
    Clear();
    srand((int)time(0));
    string Name=MonsterName[i];
    say("遭遇了");say(Name);say("！");
    printf("\n");
    int HP=MonsterHP[i];
    int Attack=MonsterAttack[i];
    int Defence=MonsterDefence[i];
    while(HP>0&&player1.HP>0)
    {
        Clear();
        say("请输入你想执行的操作：");
        printf("\n");
        say("1：攻击    2：使用技能    3：使用道具    4：逃跑");
        printf("\n");
        int x,End=1;
        cin>>x;
        if(x<0||x>4)continue;
        if(x==4)
        {
            say("逃跑成功，战斗失败");
            printf("\n");
            break;
            return -1;
        }
        if(x==1)
        {
            if(player1.Attack<Defence)
            {
                say("攻击小于对手防御，建议逃跑或使用道具");
                printf("\n");
            }
            else 
            {
                HP-=player1.Attack-Defence;
                say("对敌人造成");printf("%d",player1.Attack-Defence);say("点伤害");
            }
        }
        if(x==2)
        {
            say("请输入想要使用的技能编号:(1为火球术,2为雷暴术,3为治疗术)");
            printf("\n");
            int y;
            cin>>y;
            if(y==1&&!player1.SKill1Level)
            {
                say("火球术尚未学习！");
                printf("\n");
                End=0;
            }
            if(y==2&&!player1.SKill2Level)
            {
                say("雷暴术尚未学习！");
                printf("\n");
                End=0;
            }
            if(y==3&&!player1.SKill3Level)
            {
                say("治疗术尚未学习！");
                printf("\n");
                End=0;
            }
            if(y==1&&player1.SKill1Level)
            {
                if(player1.MP<3)
                {
                    say("魔法值不足，使用失败");
                    printf("\n");
                    End=0;
                }
                else
                {
                    say("使用火球术，对敌人造成");printf("%d",5*player1.SKill1Level);say("点伤害");
                    printf("\n");
                    say("消耗3点魔法值");
                    printf("\n");
                    HP-=5*player1.SKill1Level;
                    player1.MP-=3;
                }
            }
            if(y==2&&player1.SKill2Level)
            {
                if(player1.MP<5)
                {
                    say("魔法值不足，使用失败");
                    printf("\n");
                    End=0;
                }
                else
                {
                    say("使用雷暴术，对敌人造成");printf("%d",10*player1.SKill2Level);say("点伤害");
                    printf("\n");
                    say("消耗5点魔法值");
                    printf("\n");
                    HP-=10*player1.SKill2Level;
                    player1.MP-=5;
                }
            }
            if(y==3&&player1.SKill3Level)
            {
                if(player1.MP<10)
                {
                    say("魔法值不足，使用失败");
                    printf("\n");
                    End=0;
                }
                else
                {
                    say("使用治疗术，回复");printf("%d",15*player1.SKill3Level);say("点血量");
                    printf("\n");
                    say("消耗10点魔法值");
                    printf("\n");
                    player1.HP=min(player1.MaxHP,player1.HP+15*player1.SKill3Level);
                    player1.MP-=10;
                }
            }
        }
        if(x==3)
        {
            say("请输入想要使用的道具编号，想查询道具的编号请输入-1");
            printf("\n");
            int y;
            cin>>y;
            if(y==-1)
            {
                say("1：小血瓶");
                printf("\n");
                say("2：中血瓶");
                printf("\n");
                say("3：大血瓶");
                printf("\n");
                say("4：小魔瓶");
                printf("\n");
                say("5：中魔瓶");
                printf("\n");
                say("6：大魔瓶");
                printf("\n");
                say("7：小炸弹");
                printf("\n");
                say("8：中炸弹");
                printf("\n");
                say("9：大炸弹");
                printf("\n");
                say("10：原子弹");
                printf("\n");
                End=0;
            }
            else if(CanUse(y)&&y<=6)Use(y);
                else if(CanUse(y)&&y>6)
                    {
                        if(y==7)
                        {
                            Slowsay("成功使用小炸弹，对敌人造成50点伤害");
                            HP-=50;
                            player1.SmallAttack--;
                        }
                        if(y==8)
                        {
                            Slowsay("成功使用中炸弹，对敌人造成100点伤害");
                            HP-=100;
                            player1.MiddleAttack--;
                        }
                        if(y==9)
                        {
                            Slowsay("成功使用大炸弹，对敌人造成200点伤害");
                            HP-=200;
                            player1.LargeAttack--;
                        }
                        if(y==10)
                        {
                            Slowsay("成功使用原子弹，对敌人造成500点伤害");
                            HP-=500;
                            player1.SuperAttack--;
                        }
                    }
                else
                {
                    say("道具不足，无法使用");
                    printf("\n");
                    End=0;
                }
        }
        if(End)
        {
            player1.HP-=Attack-player1.Defence;
            say(Name);say("对你造成了");printf("%d",Attack-player1.Defence);say("点伤害");
            printf("\n");
        }
    }
    if(player1.HP<=0){Die();return 0;}
    else
    {
        say("战斗胜利！获得");
        int XP=rand();
        printf("%d",XP);
        say("点经验");
        printf("\n");
        player1.Experience+=XP;
        return 1;
    }
}
void Level()
{
    int EXP=player1.Experience,LV=player1.Level;
    while(EXP>=LevelUp[LV+1]&&LV<=LevelMost)
    {
        LV++;
        EXP-=LevelUp[LV];
        player1.Attack+=10;
        player1.Defence+=10;
        player1.MaxHP+=50;
        player1.HP=player1.MaxHP;
        player1.MaxMP+=50;
        player1.MP=player1.MaxMP;
        player1.Money+=50;
    }
    if(LV>=5)WorkOpen=1;
    if(player1.Level==LV)Slowsay("升级失败，经验不足");
    else
    {
        say("升级成功，升了");printf("%d",LV-player1.Level);Slowsay("级");
    }
    player1.Experience=EXP;
    player1.Level=LV;
}
void LastFight()
{
    Clear();
    Slowsay("混沌魔王：没错，我就是传说中的混沌魔王！");
    Slowsay("混沌魔王：哈哈哈哈哈哈哈哈哈哈哈哈！！！！！！");
    Slowsay("混沌魔王：你就是天选之子吗？哈哈！太弱了！");
    Slowsay("混沌魔王：就凭你还想战胜我，救出公主？哼哼！想得美！");
    if(player1.Level<10)
    {
        Slowsay("少年：我要消灭你，进化吧！");
        Slowsay("混沌魔王：这...这怎么可能？！");
        Slowsay("少年：看着吧，这就是传说中的天赐圣剑和天赐圣铠！");
        player1.Experience=6666666;
        Level();
        Slowsay("混沌魔王：那你也不能战胜我！我已经封锁了你的退路！");
    }
    int HP=MonsterHP[11];
    int Attack=MonsterAttack[11];
    int Defence=MonsterDefence[11];
    while(HP>0&&player1.HP>0)
    {
        Clear();
        Slowsay("请输入你想执行的操作：");
        Slowsay("1：攻击    2：使用技能    3：使用道具");
        int x,End=1;
        cin>>x;
        if(x<0||x>3)continue;
        if(x==1)
        {
            if(player1.Attack<Defence)
            {
                say("攻击小于对手防御，建议逃跑或使用道具");
                printf("\n");
            }
            else 
            {
                HP-=player1.Attack-Defence;
                say("对敌人造成");printf("%d",player1.Attack-Defence);say("点伤害");
            }
        }
        if(x==2)
        {
            say("请输入想要使用的技能编号:(1为火球术,2为雷暴术,3为治疗术)");
            printf("\n");
            int y;
            cin>>y;
            if(y==1&&!player1.SKill1Level)
            {
                say("火球术尚未学习！");
                printf("\n");
                End=0;
            }
            if(y==2&&!player1.SKill2Level)
            {
                say("雷暴术尚未学习！");
                printf("\n");
                End=0;
            }
            if(y==3&&!player1.SKill3Level)
            {
                say("治疗术尚未学习！");
                printf("\n");
                End=0;
            }
            if(y==1&&player1.SKill1Level)
            {
                if(player1.MP<3)
                {
                    say("魔法值不足，使用失败");
                    printf("\n");
                    End=0;
                }
                else
                {
                    say("使用火球术，对敌人造成");printf("%d",5*player1.SKill1Level);say("点伤害");
                    printf("\n");
                    say("消耗3点魔法值");
                    printf("\n");
                    HP-=5*player1.SKill1Level;
                    player1.MP-=3;
                }
            }
            if(y==2&&player1.SKill2Level)
            {
                if(player1.MP<5)
                {
                    say("魔法值不足，使用失败");
                    printf("\n");
                    End=0;
                }
                else
                {
                    say("使用雷暴术，对敌人造成");printf("%d",10*player1.SKill2Level);say("点伤害");
                    printf("\n");
                    say("消耗5点魔法值");
                    printf("\n");
                    HP-=10*player1.SKill2Level;
                    player1.MP-=5;
                }
            }
            if(y==3&&player1.SKill3Level)
            {
                if(player1.MP<10)
                {
                    say("魔法值不足，使用失败");
                    printf("\n");
                    End=0;
                }
                else
                {
                    say("使用治疗术，回复");printf("%d",15*player1.SKill3Level);say("点血量");
                    printf("\n");
                    say("消耗10点魔法值");
                    printf("\n");
                    player1.HP=min(player1.MaxHP,player1.HP+15*player1.SKill3Level);
                    player1.MP-=10;
                }
            }
        }
        if(x==3)
        {
            say("请输入想要使用的道具编号，想查询道具的编号请输入-1");
            printf("\n");
            int y;
            cin>>y;
            if(y==-1)
            {
                say("1：小血瓶");
                printf("\n");
                say("2：中血瓶");
                printf("\n");
                say("3：大血瓶");
                printf("\n");
                say("4：小魔瓶");
                printf("\n");
                say("5：中魔瓶");
                printf("\n");
                say("6：大魔瓶");
                printf("\n");
                say("7：小炸弹");
                printf("\n");
                say("8：中炸弹");
                printf("\n");
                say("9：大炸弹");
                printf("\n");
                say("10：原子弹");
                printf("\n");
                End=0;
            }
            else if(CanUse(y)&&y<=6)Use(y);
                else if(CanUse(y)&&y>6)
                    {
                        if(y==7)
                        {
                            Slowsay("成功使用小炸弹，对敌人造成50点伤害");
                            HP-=50;
                            player1.SmallAttack--;
                        }
                        if(y==8)
                        {
                            Slowsay("成功使用中炸弹，对敌人造成100点伤害");
                            HP-=100;
                            player1.MiddleAttack--;
                        }
                        if(y==9)
                        {
                            Slowsay("成功使用大炸弹，对敌人造成200点伤害");
                            HP-=200;
                            player1.LargeAttack--;
                        }
                        if(y==10)
                        {
                            Slowsay("成功使用原子弹，对敌人造成500点伤害");
                            HP-=500;
                            player1.SuperAttack--;
                        }
                    }
                else
                {
                    say("道具不足，无法使用");
                    printf("\n");
                    End=0;
                }
        }
        if(End)
        {
            player1.HP-=Attack-player1.Defence;
            say("混沌魔王对你造成了");printf("%d",Attack-player1.Defence);say("点伤害");
            printf("\n");
        }
    }
    if(player1.HP<=0)Die();
    else TheEnd();
}
void Battle(int Level)
{
    if(Level==1)
    {
        srand((int)time(0));
        int i=rand();
        while(i<1||(i>3&&i<6)||i>8)i=rand();
        Fight(i);
    }
    if(Level==2)
    {
        srand((int)time(0));
        int i=rand();
        while(i<2||(i>4&&i<7)||i>9)i=rand();
        Fight(i);
    }
    if(Level==3)
    {
        srand((int)time(0));
        int i=rand();
        while(i<3||(i>5&&i<8)||i>10)i=rand();
        Fight(i);
    }
    if(Level==4)
    {
        srand((int)time(0));
        int i=rand();
        while(i<4||(i>6&&i<9)||i>11)i=rand();
        if(i!=11)Fight(i);
        else LastFight();
    }
}
void Forest()
{
    Clear();
    Slowsay("1.草原（易，怪物级别1~3）");
    Slowsay("2.悬崖（中，怪物级别2~4）");
    Slowsay("3.洞穴（难，怪物级别3~5）"); 
    Slowsay("4.邪恶基地（极难，怪物级别4~6）");
    int x;
    Slowsay("请输入你想去的地方（序号，1~4）");
    cin>>x;
    Battle(x);
}
void Out()
{
    cout<<"HP:"<<player1.HP<<endl;
    Sleep(1000);
    cout<<"MaxHP:"<<player1.MaxHP<<endl;
    Sleep(1000);
    cout<<"MP:"<<player1.MP<<endl;
    Sleep(1000);
    cout<<"MaxMP:"<<player1.MaxMP<<endl;
    Sleep(1000);
    cout<<"ATK:"<<player1.Attack<<endl;
    Sleep(1000);
    cout<<"DEF:"<<player1.Defence<<endl;
    Sleep(1000);
    cout<<"EXP:"<<player1.Experience<<endl;
    Sleep(1000);
    cout<<"LV:"<<player1.Level<<endl;
    Sleep(1000);
}
int Money(int i)
{
    if(i==0)return 117;
    if(i==1)return 100;
    if(i==2)return 121;
    if(i==3)return 108;
    if(i==4)return 295;
}
void Home()
{
    while(1)
    {
        Clear();
        Slowsay("1.从家长那里拿点零花钱");
        Slowsay("2.睡觉");
        Slowsay("3.存档");
        Slowsay("4.升级圣坛");
        Slowsay("5.查看状态");
        Slowsay("6.返回");
        int x;
        Slowsay("请输入你想去的地方（序号，1~6）");
        cin>>x;
        if(x==6)break;
        if(x==1)
        {
            Slowsay("你必须要回答出我的问题，不然就滚！");
            srand((int)time(0));
            int i=rand();
            while(i>4)i=rand();
            cout<<Question[i];
            string a;
            cin>>a;
            if(a==Answer[i])
            {
                srand((int)time(0));
                int x=Money(i);
                say("真棒，");printf("%d",x);Slowsay("元就给你了");
                player1.Money+=x;
            }
            else Slowsay("这都能错，滚！");
        }
        if(x==2)
        {
            Slowsay("多么一个好觉啊，你的血量回满了");
            player1.HP=player1.MaxHP;
        }
        if(x==3){Save();break;}
        if(x==4)Level();
        if(x==5)Out();
    }
}
void Class()
{
    while(1)
    {
        Clear();
        Slowsay("这里就是我的教室了，找个人聊聊天吧");
        Slowsay("1.老师");
        Slowsay("2.同桌");
        Slowsay("3.死党");
        Slowsay("4.学霸");
        Slowsay("5.返回");
        int x;
        Slowsay("请输入你想要对话的人（序号，1~5）");
        cin>>x;
        if(x==5)break;
        if(x==1)Slowsay("你找我干什么，滚！");
        if(x==2)Slowsay("你的死党好像不高兴，去看看吧");
        if(x==3&&(Mission1Get==-1||Mission1Get==1))Slowsay("我没事儿，你走吧");
        if(x==3&&Mission1Get==0)
        {
            Slowsay("学霸这次又考第一，我们去教训他吧");
            Slowsay("接到任务：去图书馆教训学霸");
            Mission1Get=1;
        }
        if(x==4)Slowsay("哈哈，这次我又是第一，太高兴了！");
    }
}
void Study()
{
    if(Mission1Get)if(Fight(12)==1)Mission1Get=-1;
    while(1)
    {
        Clear();
        srand((int)time(0));
        Slowsay("1.学习火球术");
        Slowsay("2.学习雷暴术");
        Slowsay("3.学习治疗术");
        Slowsay("4.学习");
        Slowsay("5.返回");
        int x;
        Slowsay("请输入你想执行的操作（序号，1~5）");
        cin>>x;
        if(x==5)break;
        if(x==1)
        {
            int i=rand()%2;
            if(i)
            {
                player1.SKill1Level++;
                say("学习成功，火球术升至");printf("%d",player1.SKill1Level);Slowsay("级");
            }
            else Slowsay("学习失败");
        }
        if(x==2)
        {
            int i=rand()%2;
            if(i)
            {
                player1.SKill2Level++;
                say("学习成功，雷暴术升至");printf("%d",player1.SKill2Level);Slowsay("级");
            }
            else Slowsay("学习失败");
        }
        if(x==3)
        {
            int i=rand()%2;
            if(i)
            {
                player1.SKill3Level++;
                say("学习成功，治疗术升至");printf("%d",player1.SKill3Level);Slowsay("级");
            }
            else Slowsay("学习失败");
        }
        if(x==4)
        {
            Slowsay("#include<bits/stdc++.h>int main(){int a,b;cin>>a>>b;cout<<a+b;}");
            player1.Experience+=20;
        }
    }
}
void Eat()
{
    Clear();
    Slowsay("1.黄瓜炒茄子（10元）");
    Slowsay("2.茄子煮蛋（30元）");
    Slowsay("3.黄瓜蒸蛋（50元）");
    Slowsay("4.红烧水饺（100元）");
    Slowsay("5.清蒸面条（200元）");
    Slowsay("6.黑暗妙趣角（250元）");
    int x;
    Slowsay("请输入你想吃的食物（序号，1~6）");
    cin>>x;
    if(x==1)player1.Money-=10;
    if(x==2)player1.Money-=30;
    if(x==3)player1.Money-=50;
    if(x==4)player1.Money-=100;
    if(x==5)player1.Money-=200;
    if(x==6&&!EatingGet)
    {
        player1.Money+=250;
        Slowsay("恭喜你获得成就“不要命”，获得奖金500元");
        EatingGet=1;
    }
    if(x==6&&EatingGet)player1.Money-=250;
    Slowsay("吃饭成功");
}
void School()
{
    while(1)
    {
        Clear();
        Slowsay("1.图书馆（增加经验、学习技能）");
        Slowsay("2.教室（聊天）");
        Slowsay("3.食堂（吃奇怪的食物）");
        Slowsay("4.返回");
        int x;
        Slowsay("请输入你想去的地方（序号，1~4）");
        cin>>x;
        if(x==1)Study();
        if(x==2)Class();
        if(x==3)Eat();
        if(x==4)break;
    }
}
void Work()
{
    Clear();
    Slowsay("1.搬砖 5HP/10元 成功率66%");
    Slowsay("2.看店 5HP/20元 成功率50%");
    if(WorkOpen)Slowsay("3.抄作业 5HP/100元 成功率100%，但是需要密码");
    int x;
    if(WorkOpen)Slowsay("请输入你想做的工作（序号，1~3）");
    else Slowsay("请输入你想做的工作（序号，1~2）");
    srand((int)time(0));
    cin>>x;
    if(x==1)
    {
        int i=rand()%3;
        if(i<2)
        {
            Slowsay("搬砖成功");
            player1.HP-=5;
            player1.Money+=10;
        }
        else Slowsay("搬砖失败");
    }
    if(x==2)
    {
        int i=rand()%2;
        if(!i)
        {
            Slowsay("看店成功");
            player1.HP-=5;
            player1.Money+=20;
        }
        else Slowsay("看店失败");
    }
    if(x==3&&WorkOpen)
    {
        Slowsay("请输入密码");
        string x;
        if(x!=PassWord)Slowsay("密码错误");
        else
        {
            Slowsay("密码正确，抄作业成功");
            player1.HP-=5;
            player1.Money+=100;
        }
    }
    if(player1.HP<=0)Die();
}
void Shop()
{
    while(1)
    {
        Clear();
        Slowsay("1.小血瓶");
        Slowsay("2.中血瓶");
        Slowsay("3.大血瓶");
        Slowsay("4.小魔瓶");
        Slowsay("5.中魔瓶");
        Slowsay("6.大魔瓶");
        Slowsay("7.小炸弹");
        Slowsay("8.中炸弹");
        Slowsay("9.大炸弹");
        Slowsay("10.原子弹");
        Slowsay("11.返回");
        if(!ForestOpen)Slowsay("12.神秘钥匙");
        int x,y;
        if(!ForestOpen)Slowsay("请输入你想买的东西（序号，1~12）");
        else Slowsay("请输入你想买的东西（序号，1~11）");
        cin>>x;
        if(x==11)break;
        if(x!=12)Slowsay("请输入你想购买的数量");
        if(y==0)continue;
        if(x==1)
        {
            if(player1.Money>=10*y)
            {
                Slowsay("购买成功");
                player1.Money-=10*y;
                player1.SmallHP+=y;
            }
            else Slowsay("金钱不足，购买失败");
        }
        if(x==2)
        {
            if(player1.Money>=20*y)
            {
                Slowsay("购买成功");
                player1.Money-=20*y;
                player1.MiddleHP+=y;
            }
            else Slowsay("金钱不足，购买失败");
        }
        if(x==3)
        {
            if(player1.Money>=50*y)
            {
                Slowsay("购买成功");
                player1.Money-=50*y;
                player1.LargeHP+=y;
            }
            else Slowsay("金钱不足，购买失败");
        }
        if(x==4)
        {
            if(player1.Money>=10*y)
            {
                Slowsay("购买成功");
                player1.Money-=10*y;
                player1.SmallMP+=y;
            }
            else Slowsay("金钱不足，购买失败");
        }
        if(x==5)
        {
            if(player1.Money>=20*y)
            {
                Slowsay("购买成功");
                player1.Money-=20*y;
                player1.MiddleMP+=y;
            }
            else Slowsay("金钱不足，购买失败");
        }
        if(x==6)
        {
            if(player1.Money>=50*y)
            {
                Slowsay("购买成功");
                player1.Money-=50*y;
                player1.LargeMP+=y;
            }
            else Slowsay("金钱不足，购买失败");
        }
        if(x==7)
        {
            if(player1.Money>=10*y)
            {
                Slowsay("购买成功");
                player1.Money-=10*y;
                player1.SmallAttack+=y;
            }
            else Slowsay("金钱不足，购买失败");
        }
        if(x==8)
        {
            if(player1.Money>=20*y)
            {
                Slowsay("购买成功");
                player1.Money-=20*y;
                player1.MiddleAttack+=y;
            }
            else Slowsay("金钱不足，购买失败");
        }
        if(x==9)
        {
            if(player1.Money>=50*y)
            {
                Slowsay("购买成功");
                player1.Money-=50*y;
                player1.LargeAttack+=y;
            }
            else Slowsay("金钱不足，购买失败");
        }
        if(x==10)
        {
            if(player1.Money>=200*y)
            {
                Slowsay("购买成功");
                player1.Money-=200*y;
                player1.SuperAttack+=y;
            }
            else Slowsay("金钱不足，购买失败");
        }
        if(x==12&&!ForestOpen)
        {
            if(player1.Money>=100000)
            {
                Slowsay("购买成功，森林已解锁");
                player1.Money-=100000;
                ForestOpen=1;
            }
            else Slowsay("金钱不足，购买失败");
        }
    }
}
void Bets()
{
    Clear();
    srand((int)time(0));
    Slowsay("1.猜大小");
    Slowsay("2.猜点数");
    int x,y,z;
    Slowsay("请输入你想赌的方式（序号，1~2）");
    cin>>x;
    Slowsay("请输入你想下注的金额");
    cin>>y;
    if(x==1)
    {
        Slowsay("猜大还是小？1大，2小");
        cin>>z;
        srand((int)time(0));
        int a1=rand()%6,a2=rand()%6;
        if(a1==0)a1=6;
        if(a2==0)a2=6;
        if((a1+a2>6&&z==1)||(a1+a2<=6&&z==2))
        {
            Slowsay("你赢了，这些钱给你");
            player1.Money+=y;
        }
        else
        {
            Slowsay("你输了，这些钱我拿走了");
            player1.Money-=y;
        }
    }
    if(x==2)
    {
        srand((int)time(0));
        int a1=rand()%6;
        if(a1==0)a1=6;
        Slowsay("你想猜多少点？");
        cin>>z;
        if(z==a1)
        {
            Slowsay("你赢了，这些钱给你");
            player1.Money+=y;
        }
        else
        {
            Slowsay("你输了，这些钱我拿走了");
            player1.Money-=y;
        }
    }
}
void City()
{
    while(1)
    {
        Clear();
        Slowsay("1.打工");
        Slowsay("2.商店");
        Slowsay("3.赌博");
        Slowsay("4.返回");
        int x;
        Slowsay("请输入你想去的地方（序号，1~4）");
        cin>>x;
        if(x==4)break;
        if(x==1)Work();
        if(x==2)Shop();
        if(x==3)Bets();
    }
}
void SpecialFight()
{
    Clear();
    int HP=1000;
    int Attack=100;
    int Defence=100;
    while(HP>0&&player1.HP>0)
    {
        Clear();
        Slowsay("请输入你想执行的操作：");
        Slowsay("1：攻击    2：使用技能");
        int x,End=1;
        cin>>x;
        if(x<0||x>2)continue;
        if(x==1)
        {
            if(player1.Attack<Defence)
            {
                say("攻击小于对手防御，建议逃跑或使用道具");
                printf("\n");
            }
            else 
            {
                HP-=player1.Attack-Defence;
                say("对敌人造成");printf("%d",player1.Attack-Defence);say("点伤害");
                printf("\n");
            }
        }
        if(x==2)
        {
            say("请输入想要使用的技能编号:(1为火球术,2为雷暴术,3为治疗术)");
            printf("\n");
            int y;
            cin>>y;
            if(y==1&&!player1.SKill1Level)
            {
                say("火球术尚未学习！");
                printf("\n");
                End=0;
            }
            if(y==2&&!player1.SKill2Level)
            {
                say("雷暴术尚未学习！");
                printf("\n");
                End=0;
            }
            if(y==3&&!player1.SKill3Level)
            {
                say("治疗术尚未学习！");
                printf("\n");
                End=0;
            }
            if(y==1&&player1.SKill1Level)
            {
                if(player1.MP<3)
                {
                    say("魔法值不足，使用失败");
                    printf("\n");
                    End=0;
                }
                else
                {
                    say("使用火球术，对敌人造成");printf("%d",5*player1.SKill1Level);say("点伤害");
                    printf("\n");
                    say("消耗3点魔法值");
                    printf("\n");
                    HP-=5*player1.SKill1Level;
                    player1.MP-=3;
                }
            }
            if(y==2&&player1.SKill2Level)
            {
                if(player1.MP<5)
                {
                    say("魔法值不足，使用失败");
                    printf("\n");
                    End=0;
                }
                else
                {
                    say("使用雷暴术，对敌人造成");printf("%d",10*player1.SKill2Level);say("点伤害");
                    printf("\n");
                    say("消耗5点魔法值");
                    printf("\n");
                    HP-=10*player1.SKill2Level;
                    player1.MP-=5;
                }
            }
            if(y==3&&player1.SKill3Level)
            {
                if(player1.MP<10)
                {
                    say("魔法值不足，使用失败");
                    printf("\n");
                    End=0;
                }
                else
                {
                    say("使用治疗术，回复");printf("%d",15*player1.SKill3Level);say("点血量");
                    printf("\n");
                    say("消耗10点魔法值");
                    printf("\n");
                    player1.HP=min(player1.MaxHP,player1.HP+15*player1.SKill3Level);
                    player1.MP-=10;
                }
            }
        }
        if(End)
        {
            player1.HP-=Attack-player1.Defence;
            say("黑衣男子对你造成了");printf("%d",Attack-player1.Defence);say("点伤害");
            printf("\n");
        }
    }
    if(player1.HP<=0)Die();
    else
    {
        Clear();
        Slowsay("黑衣男子：不错嘛，小伙子！居然能战胜我！这里是100000元，就送你了！");
        Slowsay("少年：真的吗！谢谢大叔！");
        Slowsay("黑衣男子（默想）：不愧是天选之子啊！看来，他能救出公主！");
        player1.Money+=100000;
        Special=1;
    }
}
void Story1()
{
    if(Special)
    {
        Clear();
        Slowsay("这里什么也没有");
        Slowsay("少年陷入了沉思：那个穿黑衣服的大叔呢？");
        Slowsay("他可是个好人......");
        return;
    }
    Clear();
    Slowsay("少年：那个穿黑衣服的，你是谁？");
    Slowsay("黑衣男子：你无需知道我是谁，因为你马上就会变成一具尸体！");
    Slowsay("少年：你好大的口气，早晨没刷牙吧！");
    Slowsay("黑衣男子：废话少说，看招！");
    SpecialFight();
}
void SuperFight()
{
    Slowsay("精英关共有3关，中途死亡也没关系，回到原界面");
    Slowsay("第一关：神圣狮子王；第二关：神圣石怪王；第三关：混沌魔王");
    Fight(5);
    Fight(10);
    LastFight();
    player1.Attack+=233;
    player1.Defence+=233;
    player1.HP=player1.MaxHP+=233;
    player1.MP=player1.MaxMP+=233; 
}
void MainMenu()
{
    Clear();
    Slowsay("1.森林（打怪）");
    Slowsay("2.家（存档、睡觉等）");
    Slowsay("3.学校（学习、吃奇怪的食物等）");
    Slowsay("4.市中心（打工、买东西等）");
    Slowsay("5.小巷子（未知）");
    Slowsay("6.精英关（通关后有特殊奖励）");
    Slowsay("7.结束游戏（自动保存）");
    int x;
    Slowsay("请输入你想去的地方（序号，1~7）");
    cin>>x;
    if(x==1&&ForestOpen)Forest();
    if(x==1&&!ForestOpen)Slowsay("暂时无法进入，似乎需要什么神秘的钥匙");
    if(x==2)Home();
    if(x==3)School();
    if(x==4)City();
    if(x==5)Story1();
    if(x==6)SuperFight();
    if(x==7)
    {
        Save();
        life=0;
    }
}
int main()
{
    system("chcp 65001");
    system("Color E");
    Slowsay(" $$$天选之子v1.2$$ $");
    Slowsay("作者：JXH    洛谷ID：地表最弱韶身    QQ号：1156057894");
    Sleep(5000);
    system("cls");
    Slowsay("是否读取存档？（禁止读取空档或坏档，1是，0否）");
    int x;
    cin>>x;
    Clear();
    if(x==1)Read();
    else
    {
        player1.Attack=5;
        player1.HP=player1.MaxHP=player1.MaxMP=player1.MP=50;
        player1.Defence=player1.LargeAttack=player1.LargeHP=0;
        player1.LargeMP=player1.MiddleAttack=player1.MiddleHP=0;
        player1.MiddleMP=player1.SKill1Level=player1.SKill2Level=0;
        player1.SKill3Level=player1.SmallAttack=player1.SmallMP=0;
        player1.SuperAttack=0;
        Start();
        if(player1.HP==-666666)
        {
            Slowsay("冒充kkk者死！！！");
            return 0;
        }
    }
    while(life)MainMenu();
}