name: Pull Request Template
description: Pull Request
body:
  - type: checkboxes
    id: checklist
    attributes:
      label: Answers checklist.
      description: Before submitting a Pull Request, please follow the checklist and try to find the answer.
      options:
        - label: I have read the documentation of the component in question and the issue is not addressed there.
          required: true
        - label: I have searched the issue tracker for a similar issue and not found a similar issue.
          required: true
  - type: textarea
    id: issue
    attributes:
      label: General issue report
      description: Your issue report goes here.
      placeholder: ex. How do I...
    validations:
      required: true