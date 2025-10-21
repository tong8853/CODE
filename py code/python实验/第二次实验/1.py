def score_to_grade(score):
    if score >= 90:
        return '优'
    elif score >= 80:
        return '良'
    elif score >= 70:
        return '中'
    elif score >= 60:
        return '及格'
    else:
        return '不及格'

# 输入基本信息
student = {}
student['学号'] = input("请输入学号: ")
student['姓名'] = input("请输入姓名: ")
student['专业'] = input("请输入专业: ")

# 输入五科成绩（百分制）
subjects = ['语文', '数学', '外语', '体育', '计算机']
credits = []
scores = []
for subj in subjects:
    score = float(input(f"请输入{subj}成绩（百分制）: "))
    credit = float(input(f"请输入{subj}学分: "))
    scores.append(score)
    credits.append(credit)
    student[f'{subj}成绩'] = score
    student[f'{subj}等级'] = score_to_grade(score)

# 计算总分和加权平均分
total_score = sum(scores)
weighted_mean = sum(s * c for s, c in zip(scores, credits)) / sum(credits)

student['总分'] = total_score
student['加权平均分'] = round(weighted_mean, 2)

# 输出
print("\n--- 学生信息 ---")
for key, value in student.items():
    print(f"{key}: {value}")