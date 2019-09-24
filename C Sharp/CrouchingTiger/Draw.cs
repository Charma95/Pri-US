using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Drawing;
using System.Threading.Tasks;

namespace CrouchingTiger
{
    class Draw
    {
        MineTrace mine;
        public int drawMap(int width, int height)
        {
            Graphics g;
            g = Graphics.FromImage(mine.drawArea);
            Pen myPen = new Pen(Color.Black, 2f);
            g.DrawLine(myPen, 0, 0, width, height);
            mine.LandMine.Image = mine.drawArea;
            g.Dispose();
            return 0;     // no error 
        }
    }
}
