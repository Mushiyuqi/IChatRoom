#ifndef FRIENDLABEL_H
#define FRIENDLABEL_H

#include <QFrame>

namespace Ui {
class FriendLabel;
}

class FriendLabel : public QFrame
{
    Q_OBJECT

public:
    explicit FriendLabel(QWidget *parent = nullptr);
    ~FriendLabel();
    void SetText(QString text);
    int Width();
    int Height();
    QString Text();

    int GetIconWidth();

private:
    Ui::FriendLabel *ui;
    QString m_text;
    int m_width;
    int m_height;

public slots:
    void slot_close();

signals:
    void sig_close(QString);

};

#endif // FRIENDLABEL_H
