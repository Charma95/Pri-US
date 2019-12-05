using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CrouchingTiger
{
    public class Draw
    {
        public Draw() { }
        
        
        int[] minePositionX = {0, 80, 160, 240, 320, 400, 480};
        int[] minePositionY = {0, 68, 136, 204, 272, 340, 408};
        
        public void moveMine(int adress)
        {
            MineTrace mine = new MineTrace();
            int x = 0;
            int y = 0;

            x = adress / 7;
            y = adress / 7;
            mine.pBMine.Location = new Point(mine.pBMine.Location.X + minePositionX[x], mine.pBMine.Location.Y + minePositionY[y]);
        }
    }
}
