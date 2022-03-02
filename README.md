# ZhongBeiCloud
# 终北云
Scheme of data transmission based on Dynamic IP in public network

基于公网动态IP的数据传输方案

The cause of this project is my data transport demand.I assembled my own computer in the way of DIY,and plan to coding on it,so my computer can become a server.

这个项目起源于我对数据传输的需求。我组装了一台性能不错的主机，打算在上面编程，令其成为服务器。

At first,I want to get a Static IP in public network from local ISP,but it is too expensive.the cost is 1200 yuan per month in my living city.(x _ x ; )

最初，我计划购买宽带运营商的公网静态IP，但是公网静态IP过于昂贵，超出了我的承受能力。在我所在的城市，价格至少为1200/月。(x _ x ; )

然后，我计划购买云服务器作为中转，但是云服务器的带宽也过于昂贵。20M带宽的云服务器甚至比公网IP更高。

最终，我选择购买宽带运营商的动态IP服务。并且购买性能薄弱的服务器来存储IP。充当门卫。

结果就是，每个月的花费直线降低。
(  ' v ' ) 真棒。

终北云的服务端运行于linux系统，所有功能均由C语言和linux脚本完成。

终北云的linux客户端将完全由C语言来完成。

在后续，终北云的windows客户端将使用QT来完成。

