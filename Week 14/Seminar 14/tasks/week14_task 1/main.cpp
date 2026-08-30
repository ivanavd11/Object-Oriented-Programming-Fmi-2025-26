#include "AdmissionService.h"
#include "Course.h"
#include "Exceptions.h"
#include "RequirementFactory.h"
#include "Student.h"
#include "StudentSystem.h"

#include <exception>
#include <iostream>
#include <vector>

int main() {
    try {
        // =================================================
        // 1. Създаване на дисциплини
        // =================================================

        Course oop(
            "OOP",
            6,
            CourseCategory::Programming,
            true,
            true
        );

        Course dataStructures(
            "Data Structures",
            6,
            CourseCategory::Programming,
            true,
            true
        );

        Course operatingSystems(
            "Operating Systems",
            6,
            CourseCategory::Programming,
            true,
            true
        );

        Course calculus(
            "Calculus",
            6,
            CourseCategory::Mathematics,
            true,
            true
        );

        Course artificialIntelligence(
            "Artificial Intelligence",
            6,
            CourseCategory::Other,
            false,
            true
        );

        Course computerGraphics(
            "Computer Graphics",
            5,
            CourseCategory::Other,
            false,
            false
        );

        // =================================================
        // 2. Създаване на студент, който покрива условията
        // =================================================

        Student goodStudent(
            "FN1001",
            "Ivan Ivanov",
            245,
            5.20
        );

        goodStudent.addCourse(oop);
        goodStudent.addCourse(dataStructures);
        goodStudent.addCourse(operatingSystems);
        goodStudent.addCourse(calculus);
        goodStudent.addCourse(artificialIntelligence);
        goodStudent.addCourse(computerGraphics);

        // =================================================
        // 3. Студент, който не покрива няколко условия
        // =================================================

        Student weakStudent(
            "FN1002",
            "Petar Petrov",
            190,
            4.10
        );

        weakStudent.addCourse(
            Course(
                "OOP",
                6,
                CourseCategory::Programming,
                true,
                true
            )
        );

        weakStudent.addCourse(
            Course(
                "Data Structures",
                6,
                CourseCategory::Programming,
                true,
                false
            )
        );

        weakStudent.addCourse(
            Course(
                "Operating Systems",
                6,
                CourseCategory::Programming,
                true,
                false
            )
        );

        weakStudent.addCourse(
            Course(
                "Calculus",
                6,
                CourseCategory::Mathematics,
                true,
                true
            )
        );

        weakStudent.addCourse(
            Course(
                "Artificial Intelligence",
                6,
                CourseCategory::Other,
                false,
                false
            )
        );

        weakStudent.addCourse(
            Course(
                "Computer Graphics",
                5,
                CourseCategory::Other,
                false,
                false
            )
        );

        // =================================================
        // 4. Конфигуриране на AdmissionService
        // =================================================

        AdmissionService baseService;

        baseService.addRequirement(
            RequirementFactory::
            createMinimumCredits(240)
        );

        baseService.addRequirement(
            RequirementFactory::
            createRequiredCourses({
                "OOP",
                "Operating Systems"
                })
        );

        baseService.addRequirement(
            RequirementFactory::
            createMinimumCoursesFromCategory(
                CourseCategory::Programming,
                3
            )
        );

        baseService.addRequirement(
            RequirementFactory::
            createMinimumElectiveCredits(5)
        );

        baseService.addRequirement(
            RequirementFactory::
            createMaximumRemainingElectives(1)
        );

        baseService.addRequirement(
            RequirementFactory::
            createMinimumAverageGrade(4.50)
        );

        baseService.addRequirement(
            RequirementFactory::
            createAllMandatoryCoursesPassed()
        );

        std::cout
            << "Base service requirements: "
            << baseService.requirementsCount()
            << '\n';

        // =================================================
        // 5. Копиране на AdmissionService
        // =================================================

        AdmissionService stricterService =
            baseService;

        // Добавяме още едно изискване само в копието.
        stricterService.addRequirement(
            RequirementFactory::
            createMinimumAverageGrade(5.50)
        );

        std::cout
            << "Stricter service requirements: "
            << stricterService.requirementsCount()
            << '\n';

        std::cout
            << "Base service requirements after copy: "
            << baseService.requirementsCount()
            << "\n\n";

        // baseService остава със 7 изисквания,
        // а stricterService има 8.
        // Това показва, че копието е независимо.

        // =================================================
        // 6. Създаване на студентска система
        // =================================================

        StudentSystem system(baseService);

        // =================================================
        // 7. Добавяне на студенти
        // =================================================

        system.addStudent(goodStudent);
        system.addStudent(weakStudent);

        std::cout
            << "Students added successfully.\n\n";

        // =================================================
        // 8. Проверка на успешно допуснат студент
        // =================================================

        std::cout << "Checking "
            << goodStudent.getName()
            << ":\n";

        AdmissionReport goodReport =
            system.checkAdmission("FN1001");

        std::cout << goodReport << '\n';

        // =================================================
        // 9 и 10. Проверка на недопуснат студент
        // и извеждане на всички причини
        // =================================================

        std::cout << "Checking "
            << weakStudent.getName()
            << ":\n";

        AdmissionReport weakReport =
            system.checkAdmission("FN1002");

        std::cout << weakReport << '\n';

        // =================================================
        // Допълнителна демонстрация на stricterService
        // =================================================

        StudentSystem stricterSystem(
            stricterService
        );

        stricterSystem.addStudent(goodStudent);

        std::cout
            << "Checking Ivan with stricter service:\n";

        std::cout
            << stricterSystem.checkAdmission("FN1001")
            << '\n';

        // При основния service Ivan е допуснат,
        // но при stricterService не е, защото
        // неговият успех е 5.20, а се изисква 5.50.

        // =================================================
        // 11. Опит за добавяне на дублиран студент
        // =================================================

        try {
            system.addStudent(goodStudent);
        }
        catch (
            const DuplicateStudentException& exception
            ) {
            std::cout
                << "Duplicate student error:\n"
                << exception.what()
                << "\n\n";
        }

        // =================================================
        // 12. Търсене на съществуващ студент
        // =================================================

        try {
            const Student& foundStudent =
                system["FN1001"];

            std::cout
                << "Found student:\n"
                << "Name: "
                << foundStudent.getName()
                << '\n'
                << "Faculty number: "
                << foundStudent.getFacultyNumber()
                << "\n\n";
        }
        catch (
            const StudentNotFoundException& exception
            ) {
            std::cout
                << exception.what()
                << '\n';
        }

        // =================================================
        // 13. Търсене на несъществуващ студент
        // =================================================

        try {
            const Student& missingStudent =
                system["FN9999"];

            std::cout
                << missingStudent.getName()
                << '\n';
        }
        catch (
            const StudentNotFoundException& exception
            ) {
            std::cout
                << "Search error:\n"
                << exception.what()
                << "\n\n";
        }

        // =================================================
        // Проверка на несъществуващ студент
        // =================================================

        try {
            AdmissionReport missingReport =
                system.checkAdmission("FN9999");

            std::cout << missingReport;
        }
        catch (
            const StudentNotFoundException& exception
            ) {
            std::cout
                << "Admission check error:\n"
                << exception.what()
                << "\n\n";
        }

        // =================================================
        // 14. Премахване на студент
        // =================================================

        system.removeStudent("FN1002");

        std::cout
            << "Student FN1002 was removed.\n";

        std::cout
            << "Students remaining in the system: "
            << system.getStudents().size()
            << "\n\n";

        // =================================================
        // 15. Опит за повторно премахване
        // =================================================

        try {
            system.removeStudent("FN1002");
        }
        catch (
            const StudentNotFoundException& exception
            ) {
            std::cout
                << "Remove error:\n"
                << exception.what()
                << "\n\n";
        }

        // =================================================
        // 16. Невалидна конфигурация през Factory
        // =================================================

        try {
            auto invalidRequirement =
                RequirementFactory::
                createMinimumAverageGrade(7.00);

            // Този ред няма да бъде достигнат.
            std::cout
                << invalidRequirement.get()
                << '\n';
        }
        catch (
            const
            InvalidRequirementConfigurationException&
            exception
            ) {
            std::cout
                << "Factory error:\n"
                << exception.what()
                << '\n';
        }
    }
    catch (const std::exception& exception) {
        std::cout
            << "Unexpected error:\n"
            << exception.what()
            << '\n';
    }

    return 0;
}