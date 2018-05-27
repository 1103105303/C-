#include<iostream>
#include<math.h>

using namespace std;
const float PI = 3.1415926;


class Point 
{
public:
	void Mover(float b_x, float b_y, float m_x, float m_y) 
	{
		value_x = b_x + m_x;
		value_y = b_y + m_y;
	}

	void Zoom(float b_x, float b_y, float m_x, float m_y,float zm)
	{
		temp_x = m_x - b_x;
		temp_y = m_y - b_y;

		value_x = temp_x * zm + b_x;
		value_y = temp_y * zm + b_y;
	}

	void Rotation(float b_x, float b_y, float m_x, float m_y, float ae)
	{
		angle = ae * PI / 180;
		s = sin(angle);
		c = cos(angle);

		temp_x = m_x - b_x;    //�^�k
		temp_y = m_y - b_y;

		value_x = temp_x * cos(angle) - temp_y * sin(angle) + b_x;     //���^�쥻����m
		value_y = temp_x * sin(angle) + temp_y * cos(angle) + b_y;
	
	}

	void Mirror(float b_x, float b_y, float m_x, float m_y, float ae)
	{
		angle = ae * PI / 180;
		s = sin(2 * angle);
		c = cos(2 * angle);

		temp_x = m_x - b_x;    //�^�k
		temp_y = m_y - b_y;

		value_x = temp_x * c + temp_y * s + b_x;    //���^�쥻����m
		value_y = temp_x * s - temp_y * s + b_y;	

	}

    private:
		float value_x, value_y;
		float temp_x, temp_y;
		float angle, s, c;

		friend ostream& operator <<(ostream& out, Point& print);

};

class triangle :public Point 
{
    public:

		void Mover(float b_x, float b_y, float x1, float y1, float x2, float y2, float x3, float y3)
		{
			pt1.Mover(b_x, b_y, x1, y1);
			pt2.Mover(b_x, b_y, x2, y2);
			pt3.Mover(b_x, b_y, x3, y3);

			cout << pt1 << pt2 << pt3;

		}


		void Zoom(float b_x, float b_y, float x1, float y1, float x2, float y2, float x3, float y3, float zm)
		{
			pt1.Zoom(b_x, b_y, x1, y1, zm);
			pt2.Zoom(b_x, b_y, x2, y2, zm);
			pt3.Zoom(b_x, b_y, x3, y3, zm);

			cout << pt1 << pt2 << pt3;

		}

		void Rotation(float b_x, float b_y, float x1, float y1, float x2, float y2, float x3, float y3, float ae)
		{
			pt1.Rotation(b_x, b_y, x1, y1, ae);
			pt2.Rotation(b_x, b_y, x2, y2, ae);
			pt3.Rotation(b_x, b_y, x3, y3, ae);

			cout << pt1 << pt2 << pt3;

		}

		void Mirror(float b_x, float b_y, float x1, float y1, float x2, float y2, float x3, float y3, float ae)
		{
			pt1.Mirror(b_x, b_y, x1, y1, ae);
			pt2.Mirror(b_x, b_y, x2, y2, ae);
			pt3.Mirror(b_x, b_y, x3, y3, ae);

			cout << pt1 << pt2 << pt3;

		}
		

  private:
	Point pt1, pt2, pt3;

};

ostream &operator<<(ostream & out, Point& print)

{
	out.setf(ios::fixed, ios::floatfield);                 //�����j��
	out.precision(1);
	out << " ( " << print.value_x << " , " << print.value_y << " )" << endl;
	return out;
}




int main() 
{
	int choice = 0;
	float x1, x2, x3, y1, y2, y3, x, y, angle, zoom;
	cout << "�п�J�Ĥ@���I" << endl;
	cin >> x1 >> y1;
	cout << "�п�J�ĤG���I" << endl;
	cin >> x2 >> y2;
	cout << "�п�J�ĤT���I" << endl;
	cin >> x3 >> y3;
	triangle tri;

	while (1) {
		cout << "�п�� 1�B���� 2�B�Y�� 3�B���� 4�B��g " << endl;
		cin >> choice;

		if (choice == 1)
		{
			cout << "�п�J�n���ʴX�Ӯy��" << endl;
			cin >> x >> y;
		}
		else 
		{
			cout << "�п�J����I" << endl;
			cin >> x >> y;
			if (choice == 3 || choice == 4)
			{
				cout << "��J����" << endl;
				cin >> angle;
			}
			else 
			{
				cout << "��J�Y�񭿲v" << endl;
				cin >> zoom;
			}
		}

		switch (choice)
		{
		case 1:
			tri.Mover(x, y, x1, y1, x2, y2, x3, y3);
			break;
		case 2:
			tri.Zoom(x, y, x1, y1, x2, y2, x3, y3, zoom);
			break;
		case 3:
			tri.Rotation(x, y, x1, y1, x2, y2, x3, y3, angle);
			break;
		case 4:
			tri.Mirror(x, y, x1, y1, x2, y2, x3, y3, angle);
			break;
		default:
			cout << "error" << endl;
			break;
		}

	}
	system("pause");
	return 0;
}