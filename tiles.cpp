#include "tiles.h"

Tiles::Tiles()
{
    map1land = QPixmap(":/map1/green land.jpg");
    map1Castle = QPixmap(":/map1/Castle.png");
    map1fence = QPixmap(":/map1/fence_00.png");
    map1Canon = QPixmap(":/map1/pngwing.com.png");

    /*fences1["topLeft"] = QPixmap();
    fences1["topRight"] = QPixmap();
    fences1["bottomLeft"] = QPixmap();
    fences1["bottomRight"] = QPixmap();
    fences1["vertical"] = QPixmap();
    fences1["horozintal"] = QPixmap();
    fences1["center"] = QPixmap();*/

    map2land = QPixmap(":/map2/desert land.png");
    map2Castle = QPixmap(":/map2/SandCastle.png");
    map2Fence = QPixmap(":/map2/SandFence.png");
    map2Canon = QPixmap(":/map2/SandTower.png");


    map3land = QPixmap(":/map3/ice land.png");
    map3Castle = QPixmap(":/map3/IceCastle.png");
    map3Fence= QPixmap(":/map3/IceFence.png");
    map3Canon = QPixmap(":/map3/IceTower.png");
}

