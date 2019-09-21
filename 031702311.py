#-*- coding: utf-8 -*- 
import json
import re
province = ["山西省","辽宁省","吉林省","黑龙江省","江苏省","浙江省","安徽省","福建省","江西省","山东省","河南省","湖北省","广东省","海南省","四川省","贵州省","云南省","陕西省","甘肃省","青海省","台湾省","河北省","湖南省","山西","辽宁","吉林","黑龙江","江苏","浙江","安徽","福建","江西","山东","河南","湖北","广东","海南","四川","贵州","云南","陕西","甘肃","青海","台湾","河北","湖南"]
province2 = ["北京市","上海市","天津市","重庆市" ]
province3 = ["北京","上海","天津","重庆" ]
city= [ "酒泉市","石家庄市","唐山市","秦皇岛市","邯郸市","邢台市","保定市","张家口市","承德市","沧州市","廊坊市","衡水市","太原市","大同市","阳泉市","长治市","晋城市","朔州市","晋中市","运城市","忻州市","临汾市","吕梁市","沈阳市","大连市","鞍山市","抚顺市","本溪市","丹东市","锦州市","营口市","阜新市","辽阳市","盘锦市","铁岭市","朝阳市","葫芦岛市","长春市","吉林市","四平市","辽源市","通化市","白山市","松原市","白城市","延边朝鲜族自治州","郑州市","开封市","洛阳市","平顶山市","安阳市","鹤壁市","新乡市","焦作市","濮阳市","许昌市","漯河市","三门峡市","南阳市","商丘市","信阳市","周口市","驻马店市","济源市","南京市","无锡市","徐州市","常州市","苏州市","南通市","连云港市","淮安市","盐城市","扬州市","镇江市","泰州市","宿迁市","杭州市","宁波市","温州市","嘉兴市","湖州市","绍兴市","金华市","衢州市","舟山市","台州市","丽水市","合肥市","芜湖市","蚌埠市","淮南市","马鞍山市","淮北市","铜陵市","安庆市","黄山市","滁州市","阜阳市","宿州市","巢湖市","六安市","亳州市","池州市","宣城市","福州市","厦门市","莆田市","三明市","泉州市","漳州市","南平市","龙岩市","宁德市","南昌市","景德镇市","萍乡市","九江市","新余市","鹰潭市","赣州市","吉安市","宜春市","抚州市","上饶市","济南市","青岛市","淄博市","枣庄市","东营市","烟台市","潍坊市","威海市","济宁市","泰安市","日照市","莱芜市","临沂市","德州市","聊城市","滨州市","菏泽市","武汉市","黄石市","襄樊市","十堰市","荆州市","宜昌市","荆门市","鄂州市","孝感市","黄冈市","咸宁市","随州市","恩施州","仙桃市","潜江市","天门市","神农架林区","长沙市","株洲市","湘潭市","衡阳市","邵阳市","岳阳市","常德市","张家界市","益阳市","郴州市","永州市","怀化市","娄底市","湘西州","广州市","深圳市","珠海市","汕头市","韶关市","佛山市","江门市","湛江市","茂名市","肇庆市","惠州市","梅州市","汕尾市","河源市","阳江市","清远市","东莞市","中山市","潮州市","揭阳市","云浮市","海口市","龙华区","秀英区","琼山区","美兰区","三亚市","成都市","自贡市","攀枝花市","泸州市","德阳市","绵阳市","广元市","遂宁市","内江市","乐山市","南充市","宜宾市","广安市","达州市","眉山市","雅安市","巴中市","资阳市","阿坝州","甘孜州","凉山州","贵阳市","六盘水市","遵义市","安顺市","铜仁地区","毕节地区","黔西南州","黔东南州","黔南州","昆明市","大理市","曲靖市","玉溪市","昭通市","楚雄市","红河市","文山市","思茅市","西双版纳市","保山市","德宏市","丽江市","怒江市","迪庆市","临沧市","西安市","铜川市","宝鸡市","咸阳市","渭南市","延安市","汉中市","榆林市","安康市","商洛市","兰州市","嘉峪关市","金昌市","白银市","天水市","武威市","张掖市","平凉市","酒泉市","庆阳市","定西市","陇南市","临夏州","甘南州","西宁市","海东地区","海北州","黄南州","海南州","果洛州","玉树州","海西州","哈尔滨市","齐齐哈尔市","鸡西市","鹤岗市","双鸭山市","大庆市","伊春市","佳木斯市","七台河市","牡丹江市","黑河市","绥化市","大兴安岭地区","呼和浩特市","包头市","乌海市","赤峰市","通辽市","鄂尔多斯市","呼伦贝尔市","巴彦淖尔市","乌兰察布市","兴安盟","锡林郭勒盟","阿拉善盟","南宁市","柳州市","桂林市","梧州市","北海市","防城港市","钦州市","贵港市","玉林市","百色市","贺州市","河池市","来宾市","崇左市","拉萨市","昌都市","山南市","日喀则市","那曲市","阿里市","林芝市","银川市","石嘴山市","吴忠市","固原市","中卫市","乌鲁木齐市","克拉玛依市","吐鲁番市","哈密市","和田地区","阿克苏地区","喀什地区","克孜勒苏柯尔克孜自治州","巴音郭楞蒙古自治州","昌吉回族自治州","博尔塔拉蒙古自治州","伊犁哈萨克自治州","塔城地区","阿勒泰地区","石河子市","阿拉尔市","图木舒克市","五家渠市","台北市","高雄市","基隆市","台中市","台南市","新竹市","嘉义市","台北县","宜兰县","桃园县","新竹县","苗栗县","台中县","彰化县","南投县","云林县","嘉义县","台南县","高雄县","屏东县","澎湖县","台东县","花莲县"]

def main():
    putin = input()
    pos = putin.find(',')
    pos_n=putin.find('!')
    name=putin[pos_n+1: pos]
    sub=putin[pos + 1:]
    pattern = re.compile(r'1[0-9]{10}')
    a = pattern.search( putin)
    telphone=a.group(0)
    sub =pattern.sub('',sub)
    sub =sub[0:len(sub)-1]
    i = 0
    sign =0
    sign2=0
    a1=""
    a2=""
    a3=""
    a4=""
    a5=""
    a6=""
    a7=""
    xiangxi_1=""
    while i< len(province):
        index = sub.find(province[i])
        if index >-1:
            a1=province[i]
            sub = sub[index + len(province[i]):]
            if province[i][-1]!="省":
                a1+="省"
            break
        i+=1
    if not a1:
        index=sub.find("自治区")
        if index>-1:
            a1=sub[0:index+3]
            sub = sub[index +3:]

    if not a1:
        i = 0
        while i< len(province2):
            index = sub.find(province2[i])
            if index >-1:
                a1=province2[i]
                a2=province3[i]
                sub = sub[index + len(province[i]):]
                break
            i+=1

    if not a2:
        i = 0
        while i< len(city):
            index = sub.find(city[i])
            if index >-1:
                a2=city[i]
                sub = sub[index + len(city[i]):]
                break
            index = sub.find(city[i][:-1])
            if index >-1:
                a2=city[i]
                sub = sub[index + len(city[i])-1:]
                break
            i+=1
    if not a2:
        index=sub.find("自治州")
        if index>-1:
            a3=sub[0:index+3]
            sub = sub[index +3:]

    index=sub.find("区")
    if index>-1:
        a3=sub[0:index+1]
        sub = sub[index +1:]
    if not a3:
        index=sub.find("县")
        if index>-1:
            a3 =sub[0:index+1]
            sub = sub[index +1:]
    if not a3:
        index=sub.find("市")
        if index>-1:
            a3=sub[0:index+1]
            sub = sub[index +1:]


    index=sub.find("镇")
    if index>-1:
        a4=sub[0:index+1]
        sub = sub[index +1:]
    if not a4:
        index=sub.find("街道")
        if index>-1:
            a4=sub[0:index+2]
            sub = sub[index +2:]
    if not a4:
        index=sub.find("经济开发区")
        if index>-1:
            a4=sub[0:index+5]
            sub = sub[index +5:]
    if not a4:
        index=sub.find("乡")
        if index>-1:
            a4=sub[0:index+1]
            sub = sub[index +1:]
    
    xiangxi_1=sub
    
    index=sub.find("路")
    if index>-1:
        a5=sub[0:index+1]
        sub = sub[index +1:]
    if not a5:
        index=sub.find("巷")
        if index>-1:
            a5=sub[0:index+1]
            sub = sub[index +1:]
    if not a5:
        index=sub.find("道")
        if index>-1:
            a5=sub[0:index+1]
            sub = sub[index +1:]
    if not a5:
        index=sub.find("胡同")
        if index>-1:
            a5=sub[0:index+2]
            sub = sub[index +2:]
    if not a5:
        index=sub.find("街区")
        if index>-1:
            a5=sub[0:index+2]
            sub = sub[index +2:]



    index=sub.find("号")
    if index>-1:
        a6=sub[0:index+1]
        sub = sub[index +1:]
    if not a6:
        index=sub.find("弄")
        if index>-1:
            a6=sub[0:index+1]
            sub = sub[index +1:]


    a7=sub
        
    if putin[0] == '1':
    
        s = {}
        f = json.loads(json.dumps(s))

        c=[]
        c.append(a1)
        c.append(a2)
        c.append(a3)
        c.append(a4)
        c.append(xiangxi_1)
        f['姓名'] = name
        f['手机'] = telphone
        f['地址'] = c
        print(json.dumps(f, ensure_ascii=False))
    
    elif putin[0] == '2':
        s = {}
        f = json.loads(json.dumps(s))
        c=[]
        c.append(a1)
        c.append(a2)
        c.append(a3)
        c.append(a4)
        c.append(a5)
        c.append(a6)
        c.append(a7)
        f['姓名'] = name
        f['手机'] = telphone
        f['地址'] = c
        print(json.dumps(f, ensure_ascii=False))

    else:
        s = {}
        f = json.loads(json.dumps(s))
        c=[]
        c.append(a1)
        c.append(a2)
        c.append(a3)
        c.append(a4)
        c.append(a5)
        c.append(a6)
        c.append(a7)
        f['姓名'] = name
        f['手机'] = telphone
        f['地址'] = c
        
        print(json.dumps(f, ensure_ascii=False))
        


main()
